public class Chore : IChore
{
    ILogger _logger;
    IMessageSender _messageSender;
    public string ChoreName { get; set; }

    public IPerson Owner { get; set; }

    public double HoursWorked { get; private set; }

    public bool IsComplete { get; private set; }

    public Chore(ILogger logger, IMessageSender messageSender)
    {
        this._logger = logger;
        this._messageSender = messageSender;
    }

    public void PerformedWork(double hours)
    {
        HoursWorked += hours;
        ILogger log = this._logger;
        log.log($"Performed work on {ChoreName}");
    }

    public void CompleteChore()
    {
        IsComplete = true;
        ILogger log = this._logger;
        log.log($"Completed {ChoreName}");
        IMessageSender emailer = this._messageSender;
        emailer.SendMessage(Owner, $"The chore {ChoreName} is complete.");
    }


}
