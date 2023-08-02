/*
I copied this from GFG.
*/

class date
{
    static int m2, d2;
    const int MAX_VALID_YR = 9999;
    const int MIN_VALID_YR = 1800;

    static int[] monthDays = { 31, 28, 31,
                               30, 31, 30,
                               31, 31, 30,
                               31, 30, 31 };

    static int countLeapYears(date d)
    {
        int years = d.y;

        // Check if the current year
        // needs to be considered
        // for the count of leap years or not
        if (d.m <= 2)
        {
            years--;
        }

        // An year is a leap year if it is
        // a multiple of 4, multiple of 400
        // and not a multiple of 100.
        return years / 4
               - years / 100
               + years / 400;
    }

    static int getDifference(date dt1, date dt2)
    {
        // COUNT TOTAL NUMBER OF DAYS
        // BEFORE FIRST DATE 'dt1'

        // initialize count using years and day
        int n1 = dt1.y * 365 + dt1.d;

        // Add days for months in given date
        for (int i = 0; i < dt1.m - 1; i++)
        {
            n1 += monthDays[i];
        }

        // Since every leap year is of 366 days,
        // Add a day for every leap year
        n1 += countLeapYears(dt1);

        // SIMILARLY, COUNT TOTAL
        // NUMBER OF DAYS BEFORE 'dt2'
        int n2 = dt2.y * 365 + dt2.d;
        for (int i = 0; i < dt2.m - 1; i++)
        {
            n2 += monthDays[i];
        }
        n2 += countLeapYears(dt2);

        // return difference between two counts
        return (n2 - n1);
    }



    public int d, m, y;
    public date(int d, int m, int y)
    {
        this.d = d;
        this.m = m;
        this.y = y;
    }

    // Returns true if
    // given year is valid.
    static bool isLeap(int year)
    {

        // Return true if year is a
        // multiple of 4 and not
        // multiple of 100. OR year
        // is multiple of 400.
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    static int offsetDays(int d, int m, int y)
    {
        int offset = d;

        if (m - 1 == 11)
            offset += 335;
        if (m - 1 == 10)
            offset += 304;
        if (m - 1 == 9)
            offset += 273;
        if (m - 1 == 8)
            offset += 243;
        if (m - 1 == 7)
            offset += 212;
        if (m - 1 == 6)
            offset += 181;
        if (m - 1 == 5)
            offset += 151;
        if (m - 1 == 4)
            offset += 120;
        if (m - 1 == 3)
            offset += 90;
        if (m - 1 == 2)
            offset += 59;
        if (m - 1 == 1)
            offset += 31;

        if (isLeap(y) && m > 2)
            offset += 1;

        return offset;
    }

    // Returns true if given
    // year is valid or not.
    public static bool isValidDate(int d, int m, int y)
    {

        // If year, month and day
        // are not in given range
        if (y > MAX_VALID_YR || y < MIN_VALID_YR)
        {
            return false;
        }
        if (m < 1 || m > 12)
        {
            return false;
        }
        if (d < 1 || d > 31)
        {
            return false;
        }

        // Handle February month
        // with leap year
        if (m == 2)
        {
            if (isLeap(y))
            {
                return (d <= 29);
            }
            else
            {
                return (d <= 28);
            }
        }

        // Months of April, June,
        // Sept and Nov must have
        // number of days less than
        // or equal to 30.
        if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            return (d <= 30);
        }
        return true;
    }

    static void revoffsetDays(int offset, int y)
    {
        int[] month = { 0, 31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31 };

        if (isLeap(y))
            month[2] = 29;
        int i;
        for (i = 1; i <= 12; i++)
        {
            if (offset <= month[i])
                break;
            offset = offset - month[i];
        }

        d2 = offset;
        m2 = i;
    }

    static void addDays(int d1, int m1, int y1, int x)
    {
        int offset1 = offsetDays(d1, m1, y1);
        int remDays = isLeap(y1) ? (366 - offset1) : (365 - offset1);

        // y2 is going to store result year and
        // offset2 is going to store offset days
        // in result year.
        int y2, offset2 = 0;
        if (x <= remDays)
        {
            y2 = y1;
            offset2 = offset1 + x;
        }

        else
        {
            // x may store thousands of days.
            // We find correct year and offset
            // in the year.
            x -= remDays;
            y2 = y1 + 1;
            int y2days = isLeap(y2) ? 366 : 365;
            while (x >= y2days)
            {
                x -= y2days;
                y2++;
                y2days = isLeap(y2) ? 366 : 365;
            }
            offset2 = x;
        }
        revoffsetDays(offset2, y2);
        Console.WriteLine("d2 = " + d2 + ", m2 = " +
                            m2 + ", y2 = " + y2);
    }

    // Driver code
    public static void Main()
    {
        date dt1 = new date(27, 2, 2021);
        date dt2 = new date(27, 9, 2022);

        // Function call
        Console.WriteLine("Pasaron "
                          + getDifference(dt1, dt2));
    }
}

