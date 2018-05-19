#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

struct P
{
    char *s;
    int l;
}
__attribute__((__packed__));

bool operator<(const P& first, const P& second)
{
    if (first.l==second.l)
        return strcmp(first.s, second.s) > 0;
    return first.l>second.l;
}

bool operator==(const P& first, const P& second)
{
    return first.l == second.l && strcmp(first.s, second.s) == 0;
}

P* out;
P* i;
P med;

P code(P* beg, P* end, int index)
{
    if (end - beg < 10)
    {
        std::sort(beg, end);
        return *(beg + index);
    }

    out = beg;
    i = beg;

    while(i + 5 < end)
    {
        std::sort(i, i+5);
        std::swap(*(out++), *(i + 2));
        i += 5;
    }
    if (i < end)
    {
        std::sort(i, end);
        std::swap(*(out++), *(i +(end - i) / 2));
    }

    med = code(beg, out,(out - beg) / 2);

    i = beg;
    out = beg;

    while(i < end)
    {
        if(*i < med)
        {
            std::swap(*out, *i);
            out++;
        }
        i++;
    }

    if (index < out - beg)
        return code(beg, out, index);
    else
    {
        index -= out - beg;

        i = out;
        beg = out;
        while (i < end)
        {
            if (*i == med)
            {
                std::swap(*out, *i);
                out++;
            }
            i++;
        }

        if(index < out - beg)
            return med;

        return code(out, end, index - (out - beg));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    P tab[n];

    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::cin>>s;
        tab[i].s = new char[s.size()];
        strcpy(tab[i].s, s.c_str());

        int k;
        std::cin >> k;
        tab[i].l = k;
    }

    int number, a;
    std::cin >> number;
    std::cin >> a;

    for(int i = 0; i < a; ++i)
    {
        int which;
        std::cin >> which;

        if(which >= n)
            std::cout << "NO";
        else
        {
            P e=code(tab, tab + n, which);
            if (e.l * 2 <= number)
            {
                std::cout << e.s;
                number -= 2* e.l;
            }
            else
                std::cout << "NO";
        }
        std::cout << " ";
    }

    for (int i = 0; i < n; ++i)
        delete[] tab[i].s;

    return 0;
}
