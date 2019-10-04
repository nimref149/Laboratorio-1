#define LIBRE 0
#define OCUPADO 1

/** \brief Solicita un texto al usuario y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \param input[] char Donde se cargara el texto ingresado
 * \return void
 */
void getString(char message[],char input[]);

/** \brief Solicita al usuario un numero y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return int Devuelve el numero ingresado
 */
int getInt(char message[]);

/** \brief Solicita al usuario un numero flotante y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return float Devuelve el numero flotante
 */
float getFloat(char message[]);

/** \brief
 * \param message[] char
 * \return char
 */
char getChar(char message[]);

char getNumeroAleatorio(int desde, int hasta, int iniciar);

int esNumerico(char str[]);

int esNumericoFlotante(char str[]);

int esSoloLetras(char str[]);

int getIntValid(int* input,char message[],char eMessage[],int lowLimit,int hiLimit);

int getFloatValid(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

int getCharValid(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

int getStringLetras(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getStringLetrasEspacio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getStringFlotantes(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int confirm();

int esSoloLetrasEspacio(char str[]);



































