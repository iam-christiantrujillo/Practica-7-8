typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void imprimirIF(Lista);
void imprimirFI(Lista);
void addPrincipioLista(Lista*,int);
void addFinalLista(Lista*,int);
int agregarEn(int, int , Lista*);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);