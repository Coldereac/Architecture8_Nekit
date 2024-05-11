#include <iostream>

int main()
{
	int8_t a = 10; //змінні з числами для рахування  
	int8_t b = 10;
	/*
	* quotient: 9 remainder: 15
	*/
	int16_t res, res1; //збереження результату
	__asm {
		mov al, a //надаємо регістру al значення a
		cmp al, b //порівнюємо al та b
		je _equal //в залежності від результата переходимо до потрібної мітки
		jl _lower
		jg _greater

		_equal:
			mov res, -1 //надаємо результату значення -2
			jmp _exitt //перехід до виходу

		_greater:
			cbw
			movsx bx, b
			imul ax, bx
			sub ax, 5
			cwd
			movsx cx, a
			idiv cx
			mov res, ax
			mov res1, dx
			jmp _exitt //перехід до виходу

		_lower:
			cbw
			movsx bx, b
			cwd
			idiv bx
			inc ax
			mov res, ax
			mov res1, dx
			jmp _exitt

		_exitt:
			mov ax, 4C00h; //стандартна команда DOS

	}
	if (a == b) //виведення результату
	{
		std::cout << "result: " << res << "\n";
	}
	else
	{
		std::cout << "quotient: " << res << "\n";
		std::cout << "remainder: " << res1 << "\n";
	}
	return 0;
}