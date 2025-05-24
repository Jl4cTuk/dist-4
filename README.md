# lab4

lab4 — cli tool for encrypt & decrypt files in folder using AES-256.

## usage

шифровать папку
```bash
./build/cryptor encrypt ../test qwe
./build/cryptor decrypt ../test qwe
```

или просто файл
```bash
./build/cryptor encrypt ../test/test.txt qwe
./build/cryptor decrypt ../test/test.txt qwe
```

## builing

```bash
mkdir build && cd build
cmake ..
make
```

## features

- берётся хеш sha256 от пароля
- можно шифровать как папку так и файл отдельно
- сканнер папок проверяет на симлинки и битые ссылки, чтобы не создавалась петля и тд.
- есть тест, который проверяет что всё работает правильно

## паттерн signelton

- у объкта только однин экземпляр и точка доступа
- удалён конструктор копирования и присваивания
- конструктор в привате и напрямую не создать
- гарантия что всё хранится только в одном месте

## структура

- main.cpp - точка взаимодействия
- scanner.cpp - сканер папок и файлов
- aes.cpp - реализация аес с помощью openssl
- crypt.cpp - связывает всё воедино
