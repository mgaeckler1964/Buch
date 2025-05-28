/* thread.c - demonstration of <thread.h> */
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

static mtx_t	s_mutex;

static void syncConsoleOut( const char *text, FILE *handle ) {
	mtx_lock( &s_mutex );
	fputs(text, handle);
	mtx_unlock( &s_mutex );
}

static void setData(tss_t dataHandle) {
	clock_t	*clockTime = malloc( sizeof( clock_t ) );
	if( !clockTime ) {
		syncConsoleOut( "Fehler bei malloc\n", stderr);
	}
	else {
		*clockTime = clock();
		if( tss_set(dataHandle, clockTime) != thrd_success ) {
			syncConsoleOut( "Fehler beim Setzen der Threaddaten\n", stderr);
		}
	}
}

static clock_t readData(tss_t dataHandle) {
	clock_t	result = 0;
	clock_t *threadData = tss_get(dataHandle);
	if( threadData ) {
		result = *threadData;
	}
	else {
		syncConsoleOut( "Fehler beim Lesen der Threaddaten\n", stderr);
	}
	return result;
}

static int theThreadFunc(void *arg) {
	tss_t *threadData = arg;
	setData(*threadData);
	return (int)readData(*threadData);
}

static void theThreadDestroy(void *arg) {
	free( arg );
	printf( "Freed %p\n", arg );
}

int main(void) {
	tss_t threadData;
	thrd_t thr1, thr2;
	int result1, result2;
	
	if( mtx_init( &s_mutex, mtx_plain ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Erzeugen des Mutex\n", stderr);
		exit( -1 );
	}

	if( tss_create( &threadData, theThreadDestroy ) != thrd_success ) {
		syncConsoleOut( "Fehler beim  Erzeugen der Threaddaten\n", stderr);
		exit( -1 );
	}
	setData(threadData);

	thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); 
	if( thrd_create( &thr1, theThreadFunc, &threadData ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Erzeugen des Thread 1\n", stderr);
		exit( -1 );
	}

	thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); 
	if( thrd_create( &thr2, theThreadFunc, &threadData ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Erzeugen des Thread 2\n", stderr);
		exit( -1 );
	}

	if( thrd_join( thr1, &result1 ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Warten auf Thread 1\n", stderr);
		exit( -1 );
	}
	if( thrd_join( thr2, &result2 ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Warten auf Thread 2\n", stderr);
		exit( -1 );
	}

	clock_t timer = readData(threadData);

	printf("Main: %ld Thread1 %d Thread2 %d\n", (long)timer, result1, result2);

	tss_delete(threadData);
	mtx_destroy(&s_mutex);
	return 0;
}