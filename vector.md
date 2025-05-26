# Vectoriaus klasė

## Vectoriaus metodai

### push_back()

push_back funkcija įdeda elementą į masyvo galą

```c++
Vector<int> my_vector;

my_vector.push_back(20);

std::cout << my_vector.at(0) << std::endl;
// Išveda 20
```

### pop_back()

pop_back funkcija išėma elementą iš masyvo galo ir gražino jo vertę

```c++
Vector<int> my_vector;

my_vector.push_back(20);
my_vector.push_back(5);

std::cout << my_vector.pop_back() << std::endl;
// Išveda 20
std::cout << my_vector.pop_back() << std::endl;
// Išveda 5
```

### at()

Gražina nuorodą (refrence) į masyvo elementą nurodytame indekse. Jei indeksas už masyvo ribų išmetamas erroras

```c++
Vector<int> my_vector;

my_vector.push_back(20);

std::cout << my_vector.at(0) << std::endl;
// Išveda 20

std::cout << my_vector.at(1) << std::endl;
// std::out_of_range
// at() index out of range
```

### size()

Gražina masyvo elementų kiekį

```c++
Vector<int> my_vector;

my_vector.push_back(20);
my_vector.push_back(5);
my_vector.push_back(-7);

std::cout << my_vector.size() << std::endl;
// Išveda 3
```

### capacity()

Gražina reservuotą masyvo elementų skaičių

```c++
Vector<int> my_vector;

my_vector.push_back(20);
my_vector.push_back(5);
my_vector.push_back(-7);

std::cout << my_vector.capacity() << std::endl;
// Išveda 4
```

## Spartos analizė

* Laiko matavimui naudoajam `chrono` biblioteka
* Testavimo eiga:
  1. Pradedamas laiko matavimas
  2. Sukuriamas tuščias vector konteineris su int tipo parametru
  3. Vektorius užpildomas didėjančia skaičiū seka iki nustatyto elementų kiekio
  4. Sustabdomas laiko skaičiavimas
  5. Sunaikinamas vector konteineris
* Testai pakartojami po 10 kartų ir iš jū gaunamas vidurkis

| Elementų kiekis | std::vector greitis | Vector greitis |
|-----------------|---------------------|----------------|
| 10000           | 7.883e-06s          | 1.9581e-05s    |
| 100000          | 0.00025s            | 0.00018s       |
| 1000000         | 0.00178s            | 0.00123s       |
| 10000000        | 0.00998s            | 0.01192s       |
| 100000000       | 0.07464s            | 0.0928s        |
