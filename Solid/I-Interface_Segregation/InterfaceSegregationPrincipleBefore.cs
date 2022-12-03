public interface IDrivable // extracted interface from Car class
    {
        void GoForward();
        void TurnLeft();
        void TurnRight();
        void GoBackward();
    }

    public class Car : IDrivable
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

    public class Train : IDrivable
    {
        public void GoForward()
        {
            Console.WriteLine("Train going forward.");
        }

        public void TurnLeft()
        {
            throw new NotImplementedException(); //trains can't turn
        }

        public void TurnRight()
        {
            throw new NotImplementedException(); //trains can't turn
        }

        public void GoBackward()
        {
            Console.WriteLine("Train backing up.");
        }
    }