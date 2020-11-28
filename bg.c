#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define OUTPUT_FILE "bg_out.log"
#define INPUT_FILE "/dev/null"

int main(int argc, char* const argv[]) {
  if(argc > 1) {

    int out, in;

    unlink(OUTPUT_FILE);
    if((out = open(OUTPUT_FILE, O_WRONLY | O_CREAT, 0644)) == -1) {
      perror("open");
      return 1;
    }
    if((in = open(INPUT_FILE, O_RDONLY)) == -1) {
      perror("open");
      return 1;
    }

    if(fork()) { // Parent
      return 0;
    } else { // child
      close(0);
      dup(in);
      close(1); close(2);
      dup(out); dup(out);
      if(setsid() == -1) {
        perror("setsid");
        return 1;
      }

      execvp(argv[1], argv + 1);

      perror("execvp");
      return 1;
    }

  } else fprintf(stderr, "Missing arguments\n");
  return 0;
}
