(defun binomial (n k)
    (labels ((binomial-tail (n k num den)
        (cond ((= k 0) (/ num den)) ((> k n) 0)
            (t (binomial-tail (- n 1) (- k 1) (* num n) (* den k))))))
    (binomial-tail n k 1 1)))

(defun binomial2 (n k)
    (if (or (= k 0) (= k n)) 
        1
    (if (> k n)     
        0
    (let ((pascal (generatePascal (+ n 1))))
        (nth k (nth n pascal))))))

(defun generatePascal (rows)
    (labels ((nextRow (row)
        (append (list 1)
            (mapcar #'+ (butlast row) (rest row))
            (list 1)))
        (iter (n currentRow result)
            (if (= n 0)
            (reverse result)
                (iter (- n 1) (nextRow currentRow) (cons currentRow result)))))
        (iter rows (list 1) nil)))

(defun merge (xs ys)
    (cond ((null xs) ys)
        ((null ys) xs)
        ((<= (car xs) (car ys)) 
            (cons (car xs) (merge (cdr xs) ys)))
        (t (cons (car ys) (merge xs (cdr ys))))))

(defun mergeSort (xs)
    (if (or (null xs) (null (cdr xs)))
        xs
        (let* ((len (length xs))
            (half (floor (/ len 2)))
            (left (subseq xs 0 half))
            (right (subseq xs half)))
            (merge (mergeSort left) (mergeSort right)))))

(defun factorize (d n)
    (if (> (* d d) n)
        (list n)
    (if (zerop (mod n d))
        (cons d (factorize d (/ n d)))
        (factorize (+ d 1) n))))

(defun primeFactors (n)
    (if (<= n 1)
        nil
    (factorize 2 n)))

(defun totient (n)
    (labels ((countCoprimes (k result)
        (cond ((= k n) result)
              ((= (gcd n k) 1) (countCoprimes (+ k 1) (+ result 1)))
              (t (countCoprimes (+ k 1) result)))))
    (countCoprimes 1 0)))

(defun totient2 (n)
    (if (<= n 1)
        0
        (let* ((factors (primeFactors n))
            (product (reduce #'* factors :key #'(lambda (x) (- 1 (/ 1.0 x))))))
        (round (* n product)))))

(defun sieve (list)
    (if (null list)
        nil
    (let ((p (car list)))
        (cons p (sieve (remove-if #'(lambda (x) (zerop (mod x p))) (cdr list)))))))

(defun generateOdds (n)
    (if (<= n 1)
        nil
    (cons n (generateOdds (- n 1)))))

(defun primes (n)
    (if (< n 2)
        nil
    (sieve (generateOdds n))))

(print (binomial 10 5))
(print (binomial2 10 5))
(print (mergeSort '(5 2 9 1 5 6 10 4 13 3)))
(print (primeFactors 50))
(print (totient 5))
(print (totient2 5))
(print (sieve '(1 2 3 4 5 6 7 8 9)))