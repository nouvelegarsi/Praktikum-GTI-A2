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
Dalam OpenGL, translasi dapat dilakukan dengan mengubah sistem koordinat atau model pandangan menggunakan fungsi `glTranslatef(x, y, z)`. Parameter x, y, dan z menunjukkan besar perpindahan objek pada masing-masing sumbu koordinat. Nilai positif akan memindahkan objek ke arah kanan (sumbu x), ke atas (sumbu y), atau ke depan (sumbu z), sedangkan nilai negatif akan memindahkan objek ke arah sebaliknya.
Contoh penerapannya :
<img width="1920" height="1080" alt="Screenshot (26)" src="https://github.com/user-attachments/assets/b9341a32-1aa6-4bd8-8672-65a6cef9aacd" />

### 2. Rotasi Object
Rotasi merupakan proses memutar suatu objek terhadap titik atau sumbu tertentu tanpa mengubah bentuk dan ukuran objek tersebut. 
Dalam OpenGL, rotasi dapat dilakukan menggunakan fungsi `glRotatef(sudut, x, y, z)`. Parameter sudut menunjukkan besar derajat rotasi yang akan diterapkan pada objek, sedangkan parameter x, y, dan z menentukan sumbu rotasi yang digunakan. Pada grafika dua dimensi, rotasi biasanya dilakukan terhadap sumbu z sehingga objek akan berputar pada bidang layar.
Contoh penerapannya : 
<img width="1920" height="1080" alt="Screenshot (28)" src="https://github.com/user-attachments/assets/13ee5f87-3c6f-4851-85dc-c4db1be90f86" />

### 3. Stack Object
Dalam OpenGL, untuk menggambar beberapa objek sekaligus sering digunakan mekanisme stack matrix. 
Perintah yang digunakan adalah `glPushMatrix()` dan `glPopMatrix()`. 
Fungsi `glPushMatrix()` digunakan untuk menyimpan keadaan transformasi matriks saat ini ke dalam stack, 
sedangkan `glPopMatrix()` digunakan untuk mengembalikan matriks ke keadaan sebelumnya. 
Dengan cara ini, transformasi seperti translasi, rotasi, atau skala yang diterapkan pada suatu objek tidak akan mempengaruhi objek lain yang digambar setelahnya. Hal ini memungkinkan setiap objek memiliki transformasi yang berbeda tanpa mengganggu transformasi objek yang lain.
Contoh penerapannya : 
<img width="1920" height="1080" alt="Screenshot (24)" src="https://github.com/user-attachments/assets/ec7fb739-de1c-462f-afa3-9dccaf62dcdb" />

## Tugas 
### Membuat Mobil 2D 
Pada tugas ini dibuat sebuah mobil 2D menggunakan beberapa objek primitif OpenGL. Bagian bawah mobil dibuat menggunakan fungsi `glRectf()` karena berbentuk persegi panjang. Bagian atas mobil dan jendela dibuat menggunakan `GL_QUADS` dengan menentukan empat titik menggunakan `glVertex`. Selain itu digunakan fungsi `glTranslatef()` untuk memindahkan posisi objek pada layar. Untuk mengatur transformasi setiap objek agar tidak saling mempengaruhi, digunakan juga `glPushMatrix()` dan `glPopMatrix()` sebagai mekanisme *stack* pada OpenGL.

#### Kode Program : 
##### a. <img width="1920" height="1080" alt="Screenshot (27)" src="https://github.com/user-attachments/assets/41eb1a98-b0fd-4621-81ab-b14650b3fe76" />

##### b. <img width="1920" height="1080" alt="Screenshot (20)" src="https://github.com/user-attachments/assets/d43ef9e9-b9bb-4a9b-8c55-0a7decab22b3" />

##### c. <img width="1920" height="1080" alt="Screenshot (30)" src="https://github.com/user-attachments/assets/04de6dc8-105f-44f1-b091-dcaa0b355f30" />

##### d. <img width="1920" height="1080" alt="Screenshot (31)" src="https://github.com/user-attachments/assets/70d55f95-f774-4892-8666-cc4d5e5266e6" />

##### e. <img width="1920" height="1080" alt="Screenshot (32)" src="https://github.com/user-attachments/assets/4ae195e8-2b19-47d0-bdb8-f9d78c704892" />

#### Gambar : 
<img width="1920" height="1080" alt="Screenshot (29)" src="https://github.com/user-attachments/assets/c0774a07-3298-44c1-ae85-b1a7b6cab015" />


