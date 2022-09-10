namespace PrimeNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalNumPrimes = 0;
            var myLock = new object();
            var watch = new System.Diagnostics.Stopwatch();
            watch.Start();
            var range = Enumerable.Range(1, 500000);
            //foreach (int num in range)
            Parallel.ForEach(range, num => 
            {
                bool isNotPrime = false;
                for (int i = 2; i < num/2; i++)
                {
                    if (num % i == 0)
                    {
                        isNotPrime = true;
                        break;
                    }
                }
                if (!isNotPrime)
                {
                    lock(myLock) { 
                        totalNumPrimes++;
                    }
                }
            });
            // }
            watch.Stop();
            Console.WriteLine("Total num of primes is: {0:D}", totalNumPrimes);
            Console.WriteLine($"Execution Time: {watch.ElapsedMilliseconds} ms");
        }
    }
}

