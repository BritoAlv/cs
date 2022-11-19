public interface ITurnable
    {
        void TurnLeft();
        void TurnRight();
    }

    public interface IDrivable
    {
        void GoForward();
        void GoBackward();
    }

    public class Car : IDrivable, ITurnable
    {
        public void GoForward()
        {
            Console.WriteLine("Car going forward.");
        }

        public void TurnLeft()
        {
            Console.WriteLine("Car turns left.");
        }

        public void TurnRight()
        {
            Console.WriteLine("Car turns right.");
        }

        public void GoBackward()
        {
            Console.WriteLine("Car backing up.");
        }
    }

    public class Train : IDrivable //now, the train class only implements what it wants
    {
        public void GoForward()
        {
            Console.WriteLine("Car going forward.");
        }

        public void GoBackward()
        {
            Console.WriteLine("Car backing up.");
        }
    }