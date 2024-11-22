/**
* @file 1.h
* @author Удалов В.В.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 20.11.2024
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
/// @brief Класс для шифрования и расшифрования шифра табличной маршрутной перестановки
class modAlphaCipher
{
private:
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
/// @brief Используемый алфавит
    std::wstring numAlpha =L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
/// @brief Ассоциативный массив "номер по символу"
    std::map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
/// @brief атрибут, хранящий ключ для шифрования или расшифрования
    std::vector <int> key; //ключ
    /** @brief Преобразование строки в вектор
    * @details В вектор типа "int" с именем "result" записываются числа, которые являются индексами алфавита "numAlpha",применяемый для строки,
    * которая поступила на вход.
    * @code
    * vector<int> result;
    * for(auto c:s) {
    * result.push_back(alphaNum[c]);
    * }
    * @endcode
    * @return std::vector <int>, в котором хранятся индексы букв сообщения из алфавита "numAlpha"
    */
    std::vector<int> convert(const std::wstring& s); //преобразование строка-вектор
    /** @brief Преобразование вектора в строку
    * @details В переменную типа "wstring" с именем "result" записывается строка согласно индексам каждой буквы алфавита "numAlpha".
    * Индексы хранятся в векторе типа "int", который поступил на вход.
    * @code
    * wstring result;
    * for(auto i:v) {
    * result.push_back(numAlpha[i]);
    * }
    * @endcode
    * @return строка текста типа "wstring"
    */
    std::wstring convert(const std::vector<int>& v); //преобразование вектор-строка
    std::wstring getValidKey(const std::wstring & s);
    std::wstring getValidOpenText(const std::wstring & s);
    std::wstring getValidCipherText(const std::wstring & s);
public:
/// @brief Запрещающий конструктор без параметров
    modAlphaCipher()=delete; //запретим конструктор без параметров
/// @brief Конструктор для установки ключа
    /**@param целочисленное число ключ
    * @details число, которое пришло на вход записывается в "private" атрибут с названием "key"
    */
    modAlphaCipher(const std::wstring& skey); //конструктор для установки ключа
/// @brief Метод, предназначенный для шифрования шифром табличной маршрутной перестановки
    std::wstring encrypt(const std::wstring& open_text); //зашифрование
/// @brief Метод, предназначенный для расшифрования шифра табличной маршрутной перестановки
    std::wstring decrypt(const std::wstring& cipher_text);//расшифрование
};
/// @brief Класс для обработки исключений
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
