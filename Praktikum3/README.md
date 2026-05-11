# Praktikum 3 
## NAMA : NOUVELLA RAHMA FITRAH LEGARSI
## NIM  : 24060124120029
## LAB  : A2

Asisten Praktikum :
- Siriel Wafa Nuriel Fahri
- Indah Nurul Janah

## Proyeksi dan Animasi
### 1. Proyeksi
<img width="1920" height="1080" alt="Screenshot (36)" src="https://github.com/user-attachments/assets/18488e32-1b40-4852-a750-fd7fd9b57110" />

### 2. Kubus Berotasi 
<img width="1920" height="1080" alt="Screenshot (35)" src="https://github.com/user-attachments/assets/541a2e4d-7ad8-4637-89f2-fbd66fe9baed" />

### 3. Lengan Bergerak
<img width="1920" height="1080" alt="Screenshot (34)" src="https://github.com/user-attachments/assets/fa79d92f-40b3-4a0c-ab13-9cc3586004f8" />


## TUGAS 
### 1. Cara Kerja Kode Lengan
Kode tersebut bekerja dengan menerapkan konsep Hierarchical Modeling (Pemodelan Hierarkis), di mana pergerakan satu objek memengaruhi objek di bawahnya (anaknya). Dalam hal ini, gerakan bahu (shoulder) secara otomatis akan ikut menggerakkan seluruh lengan dan siku (elbow).
Secara langkah-langkah, berikut penjelasannya : <ebc>
1) **Inisialisasi Tampilan**  
   Program mengatur warna background dan mode shading menggunakan `glClearColor` dan `glShadeModel`.

2) **Membersihkan Layar**  
   Pada fungsi `display()`, layar dibersihkan dengan `glClear` sebelum menggambar objek baru.

3) **Transformasi Awal (Posisi Lengan)**  
   Lengan digeser ke kiri menggunakan `glTranslatef(-1.0, 0.0, 0.0)` agar terlihat di layar.

4) **Rotasi Bahu (Shoulder)**  
   Dilakukan dengan `glRotatef(shoulder, 0, 0, 1)` yang mempengaruhi seluruh bagian lengan.

5) **Menggambar Lengan Atas**  
   - Geser ke ujung bahu (`glTranslatef`)  
   - Ubah ukuran dengan `glScalef`  
   - Gambar dengan `glutWireCube`  
   Bagian ini merepresentasikan **shoulder → elbow**.

6) **Transformasi ke Siku (Elbow)**  
   Posisi dipindahkan ke ujung lengan atas menggunakan `glTranslatef`.

7) **Rotasi Siku (Elbow)**  
   Menggunakan `glRotatef(elbow, 0, 0, 1)`  
   Hanya mempengaruhi bagian lengan bawah.

8) **Menggambar Lengan Bawah**  
   Sama seperti sebelumnya (scale + cube), merepresentasikan **elbow → tangan**.

9) **Hierarchical Modeling**  
   Rotasi bahu mempengaruhi seluruh lengan, sedangkan rotasi siku hanya bagian bawah.  
   Hal ini menunjukkan konsep **transformasi berhirarki**.

10) **Interaksi Keyboard**  
    - `s / S` → menggerakkan bahu  
    - `e / E` → menggerakkan siku  
    - `ESC` → keluar program

### 2. Penambahan Telapak Tangan dan Jari-Jari 
#### Fungsi jari
<img width="1920" height="1080" alt="Screenshot (38)" src="https://github.com/user-attachments/assets/2d18133f-b52e-4678-aca8-0e53e4021ffb" />

#### Membuat objek
![Screenshot_114](https://github.com/user-attachments/assets/039bb3c2-844d-482c-8cd9-0d93b62d8b1a)

#### Interaksi keyboard
<img width="1920" height="1080" alt="Screenshot (39)" src="https://github.com/user-attachments/assets/a63799eb-acfa-4dff-af09-9d737e4bac39" />

#### Hasil 
<img width="1920" height="1080" alt="Screenshot (37)" src="https://github.com/user-attachments/assets/20b8fa8e-b579-48f2-b1a2-02199ca4154a" />

### 3. Simulasi 
#### 1. Sistem Koordinat
- Sumbu X → horizontal (kiri - kanan)
- Sumbu Y → vertikal (bawah - atas)
- Sumbu Z → kedalaman (depan - belakang)

Pada program ini, rotasi terjadi pada **sumbu Z**, sehingga gerakan terjadi di bidang **X-Y**.


#### 2. Posisi Awal (Tanpa Rotasi)
Shoulder → Elbow → Wrist

(-1,0)●────●────● (X)
      S    E    W  

Keterangan:
S = Shoulder  
E = Elbow  
W = Wrist  

#### 3. Posisi setelah di simulasikan 
##### a. Posisi 1 :
<img width="1920" height="1080" alt="Screenshot (41)" src="https://github.com/user-attachments/assets/d1fb17a6-fe88-435a-90cd-e9b526809e16" />

##### b. Posisi 2 : 
<img width="1920" height="1080" alt="Screenshot (42)" src="https://github.com/user-attachments/assets/aef07fa7-f2c9-431e-ace7-c7bef09271f7" />

##### c. Posisi 3 : 
<img width="1920" height="1080" alt="Screenshot (43)" src="https://github.com/user-attachments/assets/61beabea-c40c-45d4-a939-7baf5dddea49" />



