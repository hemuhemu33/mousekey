#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int i, opt;

    opterr = 0; //getopt()のエラーメッセージを無効にする。

    while ((opt = getopt(argc, argv, "fgh:")) != -1) {
        //コマンドライン引数のオプションがなくなるまで繰り返す
      printf("%d",opt);
        switch (opt) {
            case 'f':
                printf("-fがオプションとして渡されました\n");
                break;

            case 'g':
                printf("-gがオプションとして渡されました\n");
                break;

            case 'h':
                printf("-hがオプションとして渡されました\n");
                printf("引数optarg = %s\n", optarg);
                break;

            default: /* '?' */
                //指定していないオプションが渡された場合
                printf("Usage: %s [-f] [-g] [-h argment] arg1 ...\n", argv[0]);
                break;
        }
    }

    //オプション以外の引数を出力する
    for (i = optind; i < argc; i++) {
        printf("arg = %s\n", argv[i]);
    }

    return 0;
}
