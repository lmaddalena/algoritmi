struct library {
	const int myVal;
	int (*add)(int, int);	// puntatore a funzione
	int (*sub)(int, int);	// puntatore a funzione
};

extern const struct library Library;