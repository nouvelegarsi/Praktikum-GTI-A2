# Praktikum 2
## NAMA : NOUVELLA RAHMA FITRAH LEGARSI
## NIM  : 24060124120029
## LAB  : A2
Asisten Praktikum :
- Siriel Wafa Nuriel Fahri
- Indah Nurul Janah
## Translasi dan Rotasi
### 1. Translasi Object
Translasi merupakan proses memindahkan posisi suatu objek dari satu titik ke titik lain tanpa mengubah bentuk maupun ukuran objek tersebut. 
Dalam OpenGL, translasi dapat dilakukan dengan mengubah sistem koordinat atau model pandangan menggunakan fungsi *glTranslatef(x, y, z)*. Parameter x, y, dan z menunjukkan besar perpindahan objek pada masing-masing sumbu koordinat. Nilai positif akan memindahkan objek ke arah kanan (sumbu x), ke atas (sumbu y), atau ke depan (sumbu z), sedangkan nilai negatif akan memindahkan objek ke arah sebaliknya.
Contoh penerapannya : 
### 2. Rotasi Object
Rotasi merupakan proses memutar suatu objek terhadap titik atau sumbu tertentu tanpa mengubah bentuk dan ukuran objek tersebut. 
Dalam OpenGL, rotasi dapat dilakukan menggunakan fungsi *glRotatef(sudut, x, y, z)*. Parameter sudut menunjukkan besar derajat rotasi yang akan diterapkan pada objek, sedangkan parameter x, y, dan z menentukan sumbu rotasi yang digunakan. Pada grafika dua dimensi, rotasi biasanya dilakukan terhadap sumbu z sehingga objek akan berputar pada bidang layar.
Contoh penerapannya : 
### 3. Stack Object
Dalam OpenGL, untuk menggambar beberapa objek sekaligus sering digunakan mekanisme stack matrix. 
Perintah yang digunakan adalah *glPushMatrix()* dan *glPopMatrix()*. 
Fungsi *glPushMatrix()* digunakan untuk menyimpan keadaan transformasi matriks saat ini ke dalam stack, 
sedangkan *glPopMatrix()* digunakan untuk mengembalikan matriks ke keadaan sebelumnya. 
Dengan cara ini, transformasi seperti translasi, rotasi, atau skala yang diterapkan pada suatu objek tidak akan mempengaruhi objek lain yang digambar setelahnya. Hal ini memungkinkan setiap objek memiliki transformasi yang berbeda tanpa mengganggu transformasi objek yang lain.
Contoh penerapannya : 

## Tugas 
### Membuat Mobil 2D 
#### Kode Program : 
#### Gambar : 
