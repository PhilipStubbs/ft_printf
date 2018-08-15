
// #include "ft_printf.h"
#include <strings.h>
#include <stdio.h>
#include "src/ft_printf.h"
// #include ""


int main()
{
	wchar_t *ws = L"Α α";
	// c 
	// printf("hello %C", 0);
	ft_printf("{%.*s}", 0, "42");
	// ft_printf("%C", L'ي');;
	// ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S NICE! %C YES\n",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"", L'ي');
	// printf("[%d]\n", findwchar(ws));
	// printf("t|%hhO, %hhO\n", 0, USHRT_MAX);
	return (1);
}

