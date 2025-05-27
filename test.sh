#!/bin/bash
CHECK1=$(sha256sum ./folder/text.txt)
CHECK2=$(sha256sum ./folder/sky8.png)

./build/cryptor encrypt ../test qwe
./build/cryptor decrypt ../test qwe

echo "test folder"
if [[ $(sha256sum ./folder/text.txt) == "$CHECK1" ]]; then
    echo "text ok"
else
    echo "text wrong"
fi

if [[ $(sha256sum ./folder/sky8.png) == "$CHECK2" ]]; then
    echo "img ok"
else
    echo "img wrong"
fi

./build/cryptor encrypt ../test/test.txt qwe
./build/cryptor decrypt ../test/test.txt qwe

echo "---"
echo "test files"
if [[ $(sha256sum ./folder/text.txt) == "$CHECK1" ]]; then
    echo "text ok"
else
    echo "text wrong"
fi

./build/cryptor encrypt ../test/sky8.png qwe
./build/cryptor decrypt ../test/sky8.png qwe

if [[ $(sha256sum ./folder/sky8.png) == "$CHECK2" ]]; then
    echo "img ok"
else
    echo "img wrong"
fi