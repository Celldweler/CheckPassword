#include <iostream>
#include <string>
#include <Windows.h>
/*
Реализовать функцию, принимающую на вход строковое значение для пароля и возвращающую логическое значение, которая проверяет соответствие пароля всем
следующим ограничениям:

-длина пароля от 8 символов
-наличие хотя бы одной прописной буквы,
-наличие хотя бы одной строчной буквы,
-наличие хотя бы одной цифры,
-наличие хотя бы одного символа пунктуации,
*/

bool CheckLengthPassword(char*);
bool CheckSymbolPunctuation(char*);
bool IsDigit(char*);
bool IsBigger(char*);
bool IsLower(char*);

bool CheckPassword(char* password)
{
	if (
		CheckLengthPassword(password)&&
		(CheckSymbolPunctuation(password) ) &&
	    ( IsDigit(password) ) &&
		( IsBigger(password) ) &&
		( IsLower(password) )
		)
	{
		return true;
	}
	return false;
}

bool IsLower(char* password)
{
	int index = 0;
	for (; index < strlen(password); index++)
	{
		if (islower(password[index]))
			return true;
    }
	return false;
}
bool IsBigger(char* password)
{
	int index = 0;
	for (; index < strlen(password); index++)
	{
		if (!islower(password[index]))
			return true;

	}
	return false;
}
bool CheckLengthPassword(char* password)
{
	int index = 0,
		count = 0,
		eight = 8;

	for (; index < strlen(password); index++)
	{
		count++;

	}
	return count >= eight;

}

bool IsDigit(char* password)
{
	int index = 0;
	for ( ;index < strlen(password); index++)
	{
		bool flag = isdigit((char)password[index]);
		if (flag)
			return flag;
	}
	return false;

}
bool CheckSymbolPunctuation(char* password)
{
	int CountSymbolPunctuation = 6;
	char _MasSymbolPunctuation[] = { '.', '!', ',', '?', ':', ';' };
	int index = 0;
	bool flag = false;

	for (size_t index = 0; index < strlen(password); index++)
	 {
		for (size_t i = 0; i < CountSymbolPunctuation; i++)
		{
			if ((char)password[index] == _MasSymbolPunctuation[i])
			{
				return true;
			}

		}

	}
	return flag;
}

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	 char password[255];
	bool flag = false;
	do
	{
		if (flag)
		{
			std::cout << "Пароль несоответсвует требованиям,пожалуста убедитесь что пароль соответсвует требованиям ниже и повторите ввод!!!\n";
		}
		std::cout<<"Пожалуйста введите пароль который соответсвует следующим требованиям:\n"
				"-длина пароля от 8 символов\n"
				"-наличие хотя бы одной прописной буквы,\n"
				"-наличие хотя бы одной строчной буквы,\n"
				"-наличие хотя бы одной цифры,\n"
				"-наличие хотя бы одного символа пунктуации\n";
		
		flag = true;
		std::cout << "]$~Enter the password -> ";
		std::cin.getline(password,255);

	} while ( CheckPassword(password)!=true);
	return 0;
}
