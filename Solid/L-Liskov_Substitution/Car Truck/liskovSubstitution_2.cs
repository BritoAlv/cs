public interface IDrivable // extracted interface from Car class
    {
        void GoForward();
        void TurnLeft();
        void TurnRight();
        void GoBackward();
    }

    public class Car : IDrivable
    {
       
    }

    public class Truck : IDrivable
    {
        public void GoForward()
        {
            Console.WriteLine("Truck going forward.");
        }

        public void TurnLeft()
        {
            Console.WriteLine("Truck turns left.");
        }

        public void TurnRight()
        {
            Console.WriteLine("Truck turns right.");
        }

        public void GoBackward()
        {
            Console.WriteLine("Truck backing up.");
        }
    }