# SoalShift_modul2_B14

## Soal 1

Untuk mengerjakan soal ini kita harus membuat program daemon. 
- Lalu lakukan iterasi file dalam directory home/gipen/modul2/soal1 menggunakan fungsi readdir();. 
- Informasi file yang terbaca akan disimpan dalam variabel struct dirent *file;. 
- Langkah selanjutnya yaitu perika apakah file tersebut berextensi .png dengan cara meilhat apakah ada substring “.png” di akhir nama file tersebut. Jika file tersebut berextensi .png maka ambil nama file tersebut dan disimpan kedalam variabel filename. 
- Kemudian tambahan string “_grey.png” diakhir filename. 
- Langkah terakhir yaitu mengubah nama file sekaligus memindahkannya ke folder home/gipen/Modul2/gambar dengan menggunakan command rename “rename(lama, baru)”.

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

## Soal 3

Pada soal ini kita aka menggunakan 3 exec. 
Yang pertama digunakan untuk 
#### unzip 
yang kedua untuk 
###### touch
dan yang terakhir digunakan untuk 
#### ls
- Pertama-tama kita membuat fork untuk unzip file campur2.zip terlebih dahulu. 
- Kemudian membuat fork lagi untuk touch, yang digunakan untuk membuat file daftar.txt untuk meletakkan file berextensi .txt ke daftar.txt, digunakan file descriptor yang dibuat menggunakan command pipe. 
- Kemudian digunakan exec untuk ls, namun sebelumnya file descriptor untuk read di close terlebih dahulu, dan menggunakan command (dup2) untuk membuat copy dari file descriptor. 
- Setelah itu buka file descriptor berindex 0 yang digunakan hanya untuk read saja, dan file daftar.txt untuk write daftar file yang memiliki extensi .txt ke daftar.txt. Untuk mecari file yang berextensi .txt menggunakan command strstr().

## Soal 4

- Pertama, kita mencari kapan waktu terakhir di akses dan waktu sekarang. jika waktu sekarang - 30 <waktu kapan terkahir diakses 
- kita menlakukan perulangan dari 1 sampai ke counter(angka terakhir dr nama file yang terakhir dibuat ditambahkan 1) jika ada file yang terlewati misalnya 1, 2, 4, 5. maka program secara otomatis break dan membuat file makan_sehat3.txt. dan disimpan di dalam folder /home/gipen/Documents/makanan
counter di increment setiap menutup file lalu dilakukan terus hingga tidak memenuhi syarat perulangan tersebut
program dijalankan setiap 5 menit


## Soal 5

1. Fungsi berguna agar dapat mendekteksi key press (getch)
```c
static struct termios old, new;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      new.c_lflag |= ECHO; /* set echo mode */
  } else {
      new.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}
```
2. Fungsi Kelaparan

- Membuat fungsi kelaparan dengan parameter * ptr
- Melakukan perulangan while true
- Jika memenuhi, maka melakukan erulangan kembali ketika jeda samadengan 0
- Pause selama 1 detik
- Jika detikLapar = 1, maka
- Set detikLapar = 10
- Set statusLapar dikurangi 5
- Jika detikLapar tidak samadengan 1
- Set detikLapar kurangi 1
- Jika jeda = 0, maka
- Jika statusLapar<=0, maka
- Exit fungsi

```c
void* kelaparan (void *ptr)
{
    while(1)
    {
        // sleep(10);
        while(jeda!=0)
        {

        }
        sleep(1);
        if(detikLapar==1)
        {
            detikLapar=10;
            statusLapar-=5;            
        }
        else detikLapar-=1;
        if(jeda==0)
        {
            if(statusLapar<=0)
            {
                printf("Monster mati karena kelaparan\n");
                exit(EXIT_FAILURE);
            }

        }  
        
    }
}
```
3. Fungsi Kebersihan
- Membuat fungsi kebersihan dengan parameter * ptr
- Melakukan perulangan while true
- Jika memenuhi, maka melakukan perulangan kembali ketika jeda samadengan 0
- Pause selama 1 detik
- Set detikBersih = 10
- Set statusBersih dikurangi 5
- Jika detikBersih tidak samadengan 1
- Set detikBersih kurangi 1
- Jika jeda = 0, maka
- Jika statusBersih<=0, maka
- Exit fungsi
```c
void* kebersihan (void *ptr)
{
    while(1)
    {
        // sleep(30);
        while(jeda!=0)
        {
            
        }
        sleep(1);
        if(detikBersih==1)
        {
            detikBersih=30;
            statusBersih-=10;
        }
        else detikBersih-=1;
        if(jeda==0)
        {
            
            if(statusBersih<=0)
            {
                printf("Monster mati karena terkena terlalu kotor\n");
                exit(EXIT_FAILURE);
            }
        }
        
    }
}
```
3. Fungsi Coundown

- Membuat fungsi countdown dengan parameter * ptr
- Melakukan perulangan while true
- Jika memenuhi, maka melakukan perulangan kembali ketika jeda samadengan 0
- Jika siapMandi = 0, maka
- Pause selama 1 detik
- Kemudian melakukan pengecekan apakah detik = 0,
- Jika benar, maka set detik = 20
- Dan set siapMandi = 1
- Jika tidak benar, maka set detik = -1

```c
void* countdown (void *ptr)
{
    while(1)
    {
        while(jeda!=0)
        {
            
        }
        if(siapMandi==0)
        {
            sleep(1);
            if(detik==0)
            {
                detik=20;
                siapMandi=1;
            }
            else detik-=1;
        }
        
    }
}
```
##### Membuat Shared Memory
```c
int *jumMakan;
void* toko (void* arg){
    key_t key = 1234;


    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    jumMakan = shmat(shmid, NULL, 0);

    *jumMakan = 0;
}
```

##### Fungsi menu pertama

- Membuat fungsi menu dengan parameter arg
- Melakukan perulangan while true
- Jika memenuh, maka melakukan perulagan jika jeda =0
- Melakukan system("clear")

```c
void* menu(void *arg)
{
    while(1){
    while(jeda!=0)
    {

    }
    system("clear");
    printf("Standby Mode\n");
    printf("nama : %s\n",nama);
    printf("Health : %d\n",statusSehat);
    printf("Hunger : %d\n",statusLapar);
    printf("Hygiene : %d\n",statusBersih);
    printf("Food Left : %d\n",makanan);
    if(siapMandi==0)
    printf("Bath will be ready in %d\n",detik);
    else printf("Bath is ready\n");
    printf("Choice :\n");
    printf("1. Eat\n");
    printf("2. Bath\n");
    printf("3. Battle\n");
    printf("4. Shop\n");
    printf("5. Exit\n");
    sleep(1);
    }
}
```

##### Menu 2, Menu pada saat masuk pada menu Shop
    Membuat fungsi menu2 dengan parameter arg
    Melakukan perulangan while true]
    Jika memenuhi, maka melakukan perulangan ketika jedanya = 2
    Melakukan system("clear")
    Printf sesuai dengan kebutuhan suntuk peliharaan berbelanja
    Pause selama 1 detik

void* menu2(void *arg)
{
    while(1){
    while(jeda!=2)
    {

    }
    system("clear");
    printf("Shop Mode\n");
    printf("Shop food stock : %d\n",*jumMakan);
    printf("Your food stock : %d\n",makanan);
    printf("Choices\n");
    printf("1. Buy\n");
    printf("2. Back\n");
    sleep(1);
    }
}
4. Fungsi Main

```c

int main()
{
    char c;
    int i;
    printf("Beri nama monstermu > ");
    c=getchar();
    while(c!='\n')
    {
        nama[i]=c;
        c=getchar();
        i++;
    }
```

- Membuat fungsi main
- Deklarasi variabel c bertipe char
- Deklarasi variabel i bertike integer
- Printf "Beri nama monstermu > "
- input char untuk memberi nama peliharaan
- Melakukan perulangan ketika input yang dimasukkan bukan enter (\n)
- Jika memenuhi, maka membaca tiap karakter dan dimasukkan ke dalam variabel c
- Melakukan perintah untuk scan karakter
- Increment i

###### untuk jika user memilih '1'

- Melakukan perulangan while true
- Input angka untuk menentukan perintah (pil) yang diinginkan
- Jika pil = 1, maka
- Jika makanan>0, maka statusLapar ditambah 15
- Decrement makanan
- Jika statusLapar>200, maka statusLapar = 2000

###### untuk jika user memilih '2'

- Mengecek apakah siapMandi = 1
- Jika benar, maka statusBersih bertambah 30
- Jika statusBersih>100, maka set statusBersih = 100
- Set siapMandi = 0

###### untuk jika user memilih '3'

- Jika pil = 3, maka
- Set statusLawan = 100
- Deklarasi = 1
- Melakukan while true
- Melakukan system("clear")
- Printf untuk menampilkan status health monster dan enemy
- Printf pilihan perintah untuk battle
- Deklarasi charac bertipe char
- Melakukan fungsi getch() yang disimpan dalam charac
- Jika charac = 1, maka
- Set statusSehat dikurangi 20
- Jika statusLawan>0 (atau lawan belum kalah), maka set statusLawan dikurangi 20
- Jika statusSehat < 0, maka statusSehat = 0, jeda = 0, kemudian break
- Jika statusLawan < 0, maka set statusLawan = 0
- Jika charac = 2, maka set jeda =0 kemudian break

###### untuk jika user memilih '4'

- Jika pil = 4, maka:
- Set jeda = 2, kemudian deklarasi charac bertipe char
- Melakukan while true
- Melakukan fungsi getch() yang disimpan dalam variabel charac
- Jika charac = 1, maka :
- Melakukan pengecekan apakah shared memory jumMakan > 0,
- Jika benar, maka jumMakan dikurangi 1
- Increment makanan
- Jika charac = 2, maka :
- Set jeda = 0
- Kemudian break

###### untuk jika user memilih '5'

- Jika pil = 5, maka :
- Melakukan system("clear")
- Printf "Sampai jumpa!!"
- Melakukan perintah exit
- Break dari pengecekan
 

### Soal 5 Jual :

Deklarasi library thread

Membuat Fungsi menggunakan fungsi getch()

- Deklarasi jumMakan bertipe integer
- Deklarasi tid bertipe pthread_t
- Membuat fungsi awal dengan parameter arg
- Di dalam fungsi awal berisi perintah untuk shared memory
```c
int *jumMakan;
pthread_t tid[2];

void* awal (void* arg)
{
    key_t key = 1234;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    jumMakan = shmat(shmid, NULL, 0);
  
    *jumMakan = 0;

}
```

- Membuat fungsi menutoko dengan parameter arg
- Melakukan while true
- Printf hal yang dibutuhkan untuk shop
- Pause selama 1 detik  

```c

void* menutoko (void* arg)
{
    while(1)
    {
        system("clear");
        printf("Shop\n");
        printf("Food Stock : %d\n",*jumMakan);
        printf("Choice : \n");
        printf("1. Restock\n");
        printf("2. Exit\n");
        sleep(1);
    }

}
```
- Membuat fungsi main
- Membuat thread awal dan menutoko
- Deklarasi variabel pil bertipe char
- Melakukan perulangan while true
- Jika memenuhi maka masukka input ke dalam variabel pil
- Jika pil = 1, maka jumMakan + 1
- Jika pil = 2, maka break 

```c
void main()
{
    pthread_create(&(tid[0]),NULL,awal,NULL);
    pthread_create(&(tid[1]),NULL,menutoko,NULL);
    char pil;
    while(1)
    {
        pil=getch();
        if(pil=='1')
        {
            *jumMakan = *jumMakan + 1;
        }
        else if(pil=='2')
        {
            break;
        }
    }
}
```
