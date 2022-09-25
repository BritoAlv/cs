public static class random_utils
{
	public static int[] generate_array(int count)
	{
		Random random = new Random();
		int[] values = new int[count];

		for (int i = 0; i < count; ++i)
			values[i] = random.Next(0, 1000);

		return values;
	}
}

/* 
int[] values = RandomUtils.generateArray(10);

foreach (int entry in values)
Console.WriteLine(entry);
 */