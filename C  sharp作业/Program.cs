using System;

namespace csharp_2作业
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int n, i;
                Console.WriteLine("please input a year:");
                int year = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("please input day:");
                int day = Convert.ToInt32(Console.ReadLine());
                if (day < 1 || day > 366)
                {
                    throw new ArgumentOutOfRangeException("Day out of range!");
                }
                if ((year % 4 == 0) && ((year % 100) != 0) || year % 400 == 0)
                {
                    n = 1;
                }
                else
                {
                    n = 0;
                }
                String[] m = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
                if (n == 1)
                {
                    int[] a = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                    for (i = 0; i < 12; i++)
                    {
                        if (day > a[i])
                        {
                            day = day - a[i];
                        }
                        else
                            break;
                    }
                    Console.WriteLine("month:" + m[i]);
                    Console.WriteLine("day:" + day);
                }
                else
                {
                    int[] a = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                    for (i = 0; i < 12; i++)
                    {
                        if (day > a[i])
                        {
                            day = day - a[i];
                        }
                        else
                            break;
                    }
                    Console.WriteLine("month:" + m[i]);
                    Console.WriteLine("day:" + day);
                } 
            }
            catch(Exception caught)
            {
                Console.WriteLine(caught);
            }
        }
    }
}
