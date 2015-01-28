/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./jchuff.codelet__9.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
void  astex_codelet__9(long freq[], int codesize[257], int others[257], int __astex_addr__c1[1], int __astex_addr__c2[1], long __astex_addr__v[1]);
int main(int argc, const char **argv)
{
  long  *freq;
  int  *codesize;
  int  *others;
  int  *__astex_addr__c1;
  int  *__astex_addr__c2;
  long  *__astex_addr__v;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * freq__region_buffer = (char *) __astex_memalloc(16104);
  __astex_write_message("Reading freq value from %s\n", argv[1]);
  __astex_read_from_file(freq__region_buffer, 16104, codelet_data_file_descriptor);
  freq = (long *) (freq__region_buffer + 7296l);
  char * codesize__region_buffer = (char *) __astex_memalloc(1028);
  __astex_write_message("Reading codesize value from %s\n", argv[1]);
  __astex_read_from_file(codesize__region_buffer, 1028, codelet_data_file_descriptor);
  codesize = (int *) (codesize__region_buffer + 0l);
  char * others__region_buffer = (char *) __astex_memalloc(1028);
  __astex_write_message("Reading others value from %s\n", argv[1]);
  __astex_read_from_file(others__region_buffer, 1028, codelet_data_file_descriptor);
  others = (int *) (others__region_buffer + 0l);
  char * __astex_addr__c1__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__c1 value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__c1__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__c1 = (int *) (__astex_addr__c1__region_buffer + 0l);
  char * __astex_addr__c2__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__c2 value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__c2__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__c2 = (int *) (__astex_addr__c2__region_buffer + 0l);
  char * __astex_addr__v__region_buffer = (char *) __astex_memalloc(8);
  __astex_write_message("Reading __astex_addr__v value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__v__region_buffer, 8, codelet_data_file_descriptor);
  __astex_addr__v = (long *) (__astex_addr__v__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__9(freq, codesize, others, __astex_addr__c1, __astex_addr__c2, __astex_addr__v);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}
