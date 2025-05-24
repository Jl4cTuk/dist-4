#!/bin/bash
CHECK=$(sha256sum ./folder/text.txt)

./build/cryptor encrypt ../test qwe
./build/cryptor decrypt ../test qwe

if [[ $(sha256sum ./folder/text.txt) == "$CHECK" ]]; then
    echo "ok"
else
    echo "smth wrong"
fi

./build/cryptor encrypt ../test/test.txt qwe
./build/cryptor decrypt ../test/test.txt qwe

if [[ $(sha256sum ./folder/text.txt) == "$CHECK" ]]; then
    echo "ok"
else
    echo "smth wrong"
fi