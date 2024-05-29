with Ada.Numerics.Float_Random;         use Ada.Numerics.Float_Random;
with Ada.Text_IO;                       use Ada.Text_IO;               

procedure Dining_Philosophers is

    N : constant Positive := 5;                 -- Number of philosophers

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
    task type Philosopher (ID : Integer; First, Second : not null access Fork);
    task body Philosopher is
        Seed : Generator;
    begin
        Reset (Seed);

        for Meal in 1..Number_of_Meals loop
            Put_Line (Integer'Image (ID) & " is thinking");
            delay Duration (Random (Seed) * 1.500);

            Put_Line (Integer'Image (ID) & " is hungry");
            First.Grab;
            Second.Grab;

            Put_Line (Integer'Image (ID) & " is eating");
            delay Duration (Random (Seed) * 1.500);
            Second.Put_Down;
            First.Put_Down;
            
            Put_Line (Integer'Image (ID) & " finished eating");
        end loop;

        Put_Line (Integer'Image (ID) & " is dying");

    end Philosopher;

    Forks : array (Natural range 1..N) of aliased Fork;

    Philosophers : array (Natural range 1..N) of access Philosopher;

begin
    -- Instantiate and start Philosopher tasks
    for I in 1..N loop
        Philosophers(I) := new Philosopher (ID => I, First => Forks(I)'Access, Second => Forks((I mod N) + 1)'Access);
    end loop;
end Dining_Philosophers;