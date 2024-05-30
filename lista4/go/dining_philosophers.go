package main

import 
(
    "log"
    "math/rand"
    "os"
    "sync"
    "time"
)

const N = 5
const numOfMeals = 20

var logging = log.New(os.Stdout, "", 0)

var dining sync.WaitGroup

func generateRandom() time.Duration {
	randomDuration := 0.5 + rand.Float64()
	return time.Duration(randomDuration * float64(time.Second))
}

func philosopher(ID int, dominantHand, otherHand *sync.Mutex) {
	rand.Seed(time.Now().UnixNano()) 

	for i := 0; i < numOfMeals; i++ {
		logging.Println(ID, "is thinking")
		time.Sleep(generateRandom())

		logging.Println(ID, "is hungry")
		dominantHand.Lock()
        otherHand.Lock()

		logging.Println(ID, "is eating")
		time.Sleep(generateRandom())
		dominantHand.Unlock()
        otherHand.Unlock()

		logging.Println(ID, "finished eating")
	}

	logging.Println("is dying")
	dining.Done()
}

func main() {

	dining.Add(N)
	fork_0 := &sync.Mutex{}
	forkLeft := fork_0

	for i := 2; i <= N; i++ {
		forkRight := &sync.Mutex{}
		go philosopher(i, forkLeft, forkRight)
		forkLeft = forkRight
	}
	go philosopher(1, fork_0, forkLeft)

	dining.Wait()
}