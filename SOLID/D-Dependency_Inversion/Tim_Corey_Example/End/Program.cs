class program
{
    static void Main()
    {
        IPerson owner = Factory.CreatePerson();

        owner.FirstName = "Alvaro";
        owner.LastName = "Brito";
        owner.EmailAddress = "gomzalezbritoalvaro@gmail.com";
        owner.PhoneNumber = "55432020";

        IChore chore = Factory.CreateChore();

        chore.ChoreName = "Design A Project";
        chore.Owner = owner;


        chore.PerformedWork(3);
        chore.PerformedWork(1.5);
        chore.CompleteChore();
    }
}
