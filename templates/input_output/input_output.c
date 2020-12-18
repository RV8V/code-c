#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input_output_a() {
  FILE *p_file = NULL;
  char *test_str = "input_output_a";
  size_t len = strlen(test_str);

  p_file = fopen("text.txt", "a+");
  fwrite(test_str, sizeof(char), len, p_file);

  fflush(p_file);

  int i = 2;
  do fwrite(test_str, sizeof(char), len, p_file);
  while(i-- > 0);

  fclose(p_file);
}

void input_output_b() {
  FILE *p_file = NULL;
  char *test_str = "input_output_b";
  size_t len = strlen(test_str);

  p_file = fopen("file.txt", "a+";
  setbuf(p_file, NULL);

  int i = 0;
  for (; i < 4; ++i)
    fwrite(test_str, sizeof(char), len, p_file);
  fclose(p_file);
}

void input_output_a_error() {
  FILE *p_file = NULL;
  char *test_str = "input_output_a_error, small buffer";
  char buffer[10] = { 0 };
  size_t len = strlen(test_str);

  p_file = fopen("file.txt", "a+");
  setbuf(p_file, buffer);

  char g = 5;
  do {
    fwrite(test_str, sizeof(char), len, p_file);
    fflush(p_file);
  } while(g-- > 0);
  fclose(p_file);
}

void input_output_b_error() {
  FILE *p_file = NULL;
  char *test_str = "input_output_b_error, small buffer";
  char buffer[20] = { 0 };
  size_t len = strlen(test_str);

  p_file = fopen("file.txt", "a+");
  setbuf(p_file, buffer);

  char g = 5;
  do fwrite(test_str, sizeof(char), len, p_file);
  while(g-- > 0);

  g = 5;
  do {
    fwrite(test_str, sizeof(char), len, p_file);
    fflush(p_file);
  } while(g-- > 0);
  fclose(p_file);
}

void input_output_e() {
  FILE *p_file = NULL;
  char *test_str = "input_output_e";
  char buffer[BUF_SIZE] = { 0 };
  size_t len = strlen(test_str);

  p_file = fopen("file.txt", "a+");
  setvbuf(p_file, buffer, _IOFBF, BUF_SIZE);

  char h = 3;
  do fwrite(test_str, sizeof(char), len, p_file);
  while(h-- > 0);

  h = 5;
  do {
    fwrite(test_str, sizeof(char), len, p_file);
    fflush(p_file);
  } while(h-- > 0);
  fclose(p_file);
}

void input_output_struct_a() {
  Test1 data_write;
  Test1 data_read;
  data_write.id = 123;
  data_write.value = 3018;

  FILE *pf_write = NULL, *pf_read = NULL;

  pf_write = fopen("save_data_1.txt", "w");
  fwrite(&data_write, sizeof(Test1), 1, pf_write);
  fclose(pf_write);

  pf_read = fopen("save_data_1.txt", "r");
  fread(&data_read, sizeof(Test1), 1, pf_write);
  fclose(pf_read);
}

void input_output_struct_b() {
  Test1 data_write;
  Test1 data_read;
  data_write.id = 123;
  data_write.value = 3018;

  FILE *pf_write = NULL, *pf_read = NULL;

  pf_write = fopen("save_data_2.txt", "w");
  fpintf(data_write, "%d\n%d", data_write.id, data_write.value);
  fclose(pf_write);

  pf_read = fopen("save_data_2.txt", "r");
  fscanf(pf_read, "%d\n%d", &data_read.id, &data_read.value;
  fclose(pf_read);
}
