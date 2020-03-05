#include <iostream>
#include <string>
#include <CTYPE.H>
/*
Реализовать функцию, принимающую на вход строковое значение для пароля и возвращающую логическое значение, которая проверяет соответствие пароля всем
следующим ограничениям:

-длина пароля от 8 символов
-наличие хотя бы одной прописной буквы,
-наличие хотя бы одной строчной буквы,
-наличие хотя бы одной цифры,
-наличие хотя бы одного символа пунктуации,
*/

bool CheckPassword(char password[])
{
	if (
		CheckLengthPassword(password) &&
		CheckSymbolPunctuation(password) &&
		IsDigit(password) &&
		IsBigger(password) &&
		IsLower(password)
		)
	{
		return true;
	}
	return false;
}

bool IsLower(char password[])
{
	int index = 0;
	while ((char)password[index] != '\0')
	{
		if (islower(password[index]))
			return true;
		index++;
	}
	return false;
}
bool IsBigger(char password[])
{
	int index = 0;
	while ((char)password[index] != '\0')
	{
		if (!islower(password[index]))
			return true;
		index++;

	}
	return false;
}
bool CheckLengthPassword(char password[])
{
	int index = 0,
	    count = 0,
		eight = 8;
	
	while ((char)password[index] != '\0')
	{
		count++;
		index++;

	}
	return count >= eight;
}

bool IsDigit(char password[])
{
	int index = 0;
	while ((char)password[index] != '\0')
	{
		bool flag=isdigit((char)password[index]);
		if (flag)
			return flag;
		index++;

		
	}
	
}
bool CheckSymbolPunctuation(char password[])
{
	int CountSymbolPunctuation=6;
	char _MasSymbolPunctuation[] = { '.', '!', ',', '?', ':', ';' };
	int index = 0;
	bool flag = false;
	while ((char)password[index] != '\0')
	{
		for (size_t i = 0; i < CountSymbolPunctuation; i++)
		{
			if ((char)password[index] == _MasSymbolPunctuation[i])
				return true;
			index++;

		}

	}
	return flag;
}

int main(int argc,char*argv[])
{
	do
	{
		char* password;
		std::cout << "]$~Enter the password -> ";
		std::cin >> password;
		exit(666);
	} while ( CheckPassword(password) );
		return 0;
}