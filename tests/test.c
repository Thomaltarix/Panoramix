/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
