#include <stdio.h>
#include <stdlib.h>


typedef struct tAlbum
{
    int *lacunas, total_espacos, espacos_vazios;
} Album;

Album* abrir_album(int);
void fechar_album(Album*);
void colar_figurinha(Album*,int);
int main()
{
    int n,m,x;
    scanf("%d %d", &n, &m);
    Album* album = abrir_album(n);

    for(int i = 0; i < m; i++)
    {
       scanf("%d", &x);
       colar_figurinha(album,x);
    }

    printf("%d\n", album->espacos_vazios);
    fechar_album(album);
    return 0;
}


Album* abrir_album(int size)
{
    Album* album = (Album*)malloc(sizeof(Album));
    if(album != NULL)
    {
        album->total_espacos = size;
        album->espacos_vazios = size;
        album->lacunas = malloc(size * sizeof(int));
        for(int i = 0; i < size; i++)
            album->lacunas[i] = 0;
    }


    return album;
}


void fechar_album(Album* album)
{
    free(album->lacunas);
    free(album);
}

void colar_figurinha(Album* album, int figurinha)
{
    int idx = figurinha-1;
    if(idx < album->total_espacos && album->lacunas[idx] == 0)//se houver espaço para figurinha e ela não foi colada
    {
        album->lacunas[idx] = figurinha;
        album->espacos_vazios--;
    }
}