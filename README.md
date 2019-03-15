# SoalShift_modul2_B14

## Soal 2
- Membubuat Struct Stat dengan variabel sb
- Lalu masukkan lokasi direktori kedalam variabel dir yang bertipe array of char
- Digunakan stat agar mendapatkan informasi dari suatu file yaitu elen.ku dalam hal ini kita membutuhkan informasi mengenai user id dan group id. Fungsi bawaan stat adalah hasilnya dimasukkan ke dalam struct stat
- Karena fungsi stat hanya memberikan informasi userId dan groupId sehingga diperlukan suatu fungsi untuk mengubah dari userID/groupId menjadi nama dari user dan groupnya, sehingga bisa menggunakan struct passwd :

#### untuk user

`struct passwd *pw = getpwuid(sb.st_uid);`
 
 getpwuid untuk ngambil detail informasi dari user id dan harus disimpan di struct passwd, variabel pw_name
 
 #### untuk group
 
`struct group  *gr = getgrgid(sb.st_gid);`

 getgrgid untuk ngambil detail informasi dari group id dan harus disimpan di struct group, variabel gr_name
 
` char ong[255] = "www-data";`

memasukknan www-data ke variabel ong
lalu 

`if(strcmp((pw->pw_name),ong)==0 && strcmp((gr->gr_name),ong)==0){
{
    chmod(dir, 0777);
    remove(dir);
}`

membandingkan antara nama owner dan nama group dengan isi dari variabel ong yaitu "www-data"
jika sama makan file elen akan di hapus dengan bantuan chmod. chmod 0777 dengan 0 didepan berati sebuah file dengan modenya dibuat menjadi read, write dan execute. Untuk menghapus file menggunakan remove.

`sleep(3)`

dijalankan setiap 3 detik dengan syarat sesuai dengan diatas

## Soal 5

- Deklarasikan variabel t dengan tipe data time_t, isi dari wvariabel t tesebut disimpan di variabel time. 
- Kemudian kita membuat struct tm bernama waktu bertipe data pointer. 
- Waktu = localtime(&t) berfungsi untuk mengkonversi waktu di time_t biar bisa kepisah pisah hari, jam, bulan.
- Selanjutnya buatlah array of character yaitu nama, Kemudian simpan hari, bulan, tahun, dan minggu didalam array of char tadi - - lalu di print nama nya dalam bentuk string. 
- Buat variabel character yang saya berinama dir. Variabel dir ini untuk menyimpan dari yang nama agar tersimpan path dimana file baru itu di buat.
- Buat folder bernama Hasil dengan chmod 777 biar bisa mengakses semua (read,write,execute).
- Deklarasi variabel i bertipe data integer, untuk perulangan untuk membuat folder setiap 30 menit.
- Dan di dalam folder tersebut buatlah file syslog dan file baru yang akan terbuat. Print file log#.log yang akan disimpan di ile baru kemudian buka file tersebut.
- Untuk memindahkan seluruh file log#.log deklarasikan pindah dengan tipe data char. Yang terakhir cek isi file syslog yang sudah kita buat kemudian isinya di simpan di suatu variabel file_baru. Kemudian tutup semua file yang kita buat. Digunakan sleep(60) dalam satuan detik karena perintah soal adalah membuat file setiap menit
