using System;

namespace fibonacci
{
    class Program
    {
        static long Finonacci(int n)
        {
            if (n == 1 || n == 2)
            {
                return 1;
            }
            long[] a = new long[n + 1];
            a[1] = a[2] = 1;
            for(int i = 3; i <= n; i++)
            {
                a[i] = a[i - 1] + a[i - 2];
            }
            return a[n];
            //return Finonacci(n - 1) + Finonacci(n - 2);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("请输入你要查询斐波那契额数列第几(1<=N<=100)项:");
            int n = int.Parse(Console.ReadLine());
            if (n < 1)
            {
                Console.WriteLine("必须大于等于1");
                return;
            } else if (n > 100)
            {
                Console.WriteLine("必须小于等于100");
                return;
            }
            Console.WriteLine(Finonacci(n));
            Console.WriteLine("请按任意键结束...");
            Console.Read();            
        }
    }
}
