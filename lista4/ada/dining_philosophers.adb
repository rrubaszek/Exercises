with Ada.Numerics.Float_Random;         use Ada.Numerics.Float_Random;
with Ada.Text_IO;                       use Ada.Text_IO;               

procedure Dining_Philosophers is

    N : constant Positive := 5;  
    type Philosopher_ID is range 1 .. N;        -- ID numbers of all N philosophers (1...N)

    protected type Fork is                      -- Represents a mutex, deadlocks will be prevented by ordering forks
        entry Grab;
        procedure Put_Down;
    private
        Taken : Boolean := False;
    end Fork;
    protected body Fork is
        entry Grab when not Taken is
        begin
            Taken := True;
        end Grab;
        procedure Put_Down is
        begin
            Taken := False;
        end Put_Down;
    end Fork;

    Number_of_Meals : constant := 20;          -- Each philosopher eats 20 times and then dies

    -- First, Second are pointers to Fork, ensuring that those aren't null
    -- Represents a philosopher with given ID, loops on all actions
    task type Philosopher (ID : Philosopher_ID; First, Second : not null access Fork);
    task body Philosopher is
        Seed : Generator;
    begin
        Reset (Seed);

        for Meal in 1..Number_of_Meals loop
            Put_Line (Philosopher_ID'Image (ID) & " is thinking");
            delay Duration (Random (Seed) * 1.500);

            Put_Line (Philosopher_ID'Image (ID) & " is hungry");
            First.Grab;
            Second.Grab;

            Put_Line (Philosopher_ID'Image (ID) & " is eating");
            delay Duration (Random (Seed) * 1.500);
            Second.Put_Down;
            First.Put_Down;
            
            Put_Line (Philosopher_ID'Image (ID) & " finished eating");
        end loop;

        Put_Line (Philosopher_ID'Image (ID) & " is dying");

    end Philosopher;

    Forks : array (1..N) of aliased Fork;

    Ph_1 : Philosopher (1,   Forks (1)'Access, Forks (2)'Access);
    Ph_2 : Philosopher (2,   Forks (2)'Access, Forks (3)'Access);
    Ph_3 : Philosopher (3,   Forks (3)'Access, Forks (4)'Access);
    Ph_4 : Philosopher (4,   Forks (4)'Access, Forks (5)'Access);
    Ph_5 : Philosopher (5,   Forks (1)'Access, Forks (5)'Access);

    --  type Philosopher_Array is array (Philosopher_ID) of access Philosopher;
    --  Philosophers : Philosopher_Array;

begin
    null;
    -- Initialize philosophers and forks
    --  for I in 1 .. N loop
    --      Forks(I) := new Fork;
    --  end loop;
    --  for I in Philosopher_ID loop
    --      declare
    --          Next_I : Philosopher_ID;
    --      begin
    --          if Integer(I) = N then
    --              Next_I := 1;
    --          else 
    --              Next_I := I + 1;
    --          end if;
    --      end;
    --      begin
    --          Philosophers(I) := new Philosopher (I, Forks(Integer(I))'Access, Forks(Integer(Next_I))'Access);
    --      end;
    --  end loop;
end Dining_Philosophers;