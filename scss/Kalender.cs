using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Masukkan tahun:");
        int year = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Masukkan bulan (1-12):");
        int month = Convert.ToInt32(Console.ReadLine());

        // Menampilkan kalender
        Console.WriteLine("Sun Mon Tue Wed Thu Fri Sat");
        
        // Mendapatkan tanggal pertama dari bulan yang diberikan
        DateTime firstDayOfMonth = new DateTime(year, month, 1);
        
        // Menentukan hari pertama dalam minggu untuk bulan dan tahun yang diberikan
        int leadingSpaces = (int)firstDayOfMonth.DayOfWeek;

        // Menampilkan ruang kosong di awal kalender
        for (int i = 0; i < leadingSpaces; i++)
        {
            Console.Write("    ");
        }

        // Menampilkan setiap hari dalam bulan
        int daysInMonth = DateTime.DaysInMonth(year, month);
        for (int day = 1; day <= daysInMonth; day++)
        {
            Console.Write($"{day,3}");

            // Jika sudah mencapai hari Sabtu, lanjutkan ke baris baru
            if ((day + leadingSpaces) % 7 == 0)
            {
                Console.WriteLine();
            }
        }
    }
}
