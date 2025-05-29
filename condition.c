/* condition.c - demonstration of ConditionVariable */
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

static const int THREAD_DELAY = 1;
static const int MAIN_PATIENCE = 2;

static mtx_t	s_consoleMutex;
static mtx_t	s_conditionMutex;
static cnd_t	s_condition;

static void syncConsoleOut( const char *text, FILE *handle ) {
	mtx_lock( &s_consoleMutex);;
	fputs(text, handle);
	mtx_unlock( &s_consoleMutex);
}

static int theThreadFunc(void *arg) {
	thrd_sleep(&(struct timespec) { .tv_sec = THREAD_DELAY }, NULL);
	if (cnd_signal(&s_condition) != thrd_success) {
		syncConsoleOut("Fehler beim Signalisieren der Condition Variable\n", stderr);
		exit(-1);
	}
	return 0;
}

int main(void) {
	thrd_t	theThread;

	if (mtx_init(&s_consoleMutex, mtx_plain) != thrd_success) {
		syncConsoleOut("Fehler beim Erzeugen des s_consoleMutex\n", stderr);
		exit(-1);
	}
	if (mtx_init(&s_conditionMutex, mtx_plain) != thrd_success) {
		syncConsoleOut("Fehler beim Erzeugen des s_conditionMutex\n", stderr);
		exit(-1);
	}
	if (cnd_init(&s_condition) != thrd_success) {
		syncConsoleOut("Fehler beim Erzeugen der Condition Variable\n", stderr);
		exit(-1);
	}

	syncConsoleOut("Start...\n", stdout);

	if (mtx_lock(&s_conditionMutex) != thrd_success) {
		syncConsoleOut("Fehler beim Sperren des s_conditionMutex\n", stderr);
		exit(-1);
	}
	if (thrd_create(&theThread, theThreadFunc, (void*)NULL) != thrd_success) {
		syncConsoleOut("Fehler beim Erzeugen des Thread\n", stderr);
		exit(-1);
	}
	time_t now = time(NULL);
	if (cnd_timedwait(&s_condition, &s_conditionMutex , &(struct timespec) {.tv_sec = now + MAIN_PATIENCE }) != thrd_success) {
		syncConsoleOut("Fehler beim Warten auf s_condition\n", stderr);
		exit(-1);
	}

	int		dummy;
	if( thrd_join(theThread, &dummy ) != thrd_success ) {
		syncConsoleOut( "Fehler beim Warten auf Thread\n", stderr);
		exit( -1 );
	}
	mtx_unlock(&s_conditionMutex);
	cnd_destroy(&s_condition);
	mtx_destroy(&s_conditionMutex);
	mtx_destroy(&s_consoleMutex);

	syncConsoleOut("Alles OK!\n", stdout);
	return 0;
}