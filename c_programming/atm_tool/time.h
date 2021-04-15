
void current_time(void){
	time_t now;
	time(&now);
	printf("\t\t\t\t%s", ctime(&now));
}
