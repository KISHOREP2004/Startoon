#include <stdio.h>

#define DATA_SIZE_1 1000
#define DATA_SIZE_2 1000  

void find_peaks(double data[], int size, int maxima[], int minima[], int *max_count, int *min_count) {
    *max_count = 0;
    *min_count = 0;

    for (int i = 1; i < size - 1; i++) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            maxima[*max_count] = i;
            (*max_count)++;
        } else if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            minima[*min_count] = i;
            (*min_count)++;
        }
    }
}

void print_indices(const char *label, int indices[], int count) {
    printf("%s Indices:\n", label);
    for (int i = 0; i < count; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");
}

void process_dataset(const char *file_name, int data_size) {
    FILE *file;
    double data[data_size];
    int maxima[data_size], minima[data_size];
    int max_count, min_count;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s!\n", file_name);
        return;
    }

    for (int i = 0; i < data_size; i++) {
        fscanf(file, "%lf", &data[i]);
    }
    fclose(file);

    find_peaks(data, data_size, maxima, minima, &max_count, &min_count);

    printf("Results for %s:\n", file_name);
    print_indices("Maxima", maxima, max_count);
    print_indices("Minima", minima, min_count);
    printf("\n");
}

int main() {

    process_dataset("Data_1.txt", DATA_SIZE_1);
    process_dataset("Data_2.txt", DATA_SIZE_2);

    return 0;
}

//Results for Data_1.txt:
//Maxima Indices:
//52 109 134 177 186 193 211 242 296 369 423 435 437 445 452 459 466 473 478 480 487 494 501 506 508 514 517 519 523 526 528 530 533 535 542 546 550 553 558 561 566 569 571 578 582 587 590 597 600 603 605 610 618 627 630 634 636 650 653 655 659 662 664 666 669 671 674 682 686 689 694 697 702 706 708 711 714 718 723 725 727 729 732 734 736 739 741 744 747 749 752 756 764 766 770 772 802 817 823 827 830 832 835 837 839 850 854 857 861 863 865 868 871 873 875 880 882 884 886 889 891 893 897 900 902 905 907 909 911 913 933 
//Minima Indices:
//8 75 112 158 182 189 194 232 243 319 391 436 444 451 458 465 472 474 477 479 481 486 493 500 502 505 507 512 516 518 520 525 527 529 532 534 538 543 547 552 555 560 567 570 585 588 594 599 601 604 607 617 629 633 635 652 654 656 661 663 665 667 670 673 675 679 683 688 691 696 703 707 709 712 716 721 724 726 728 730 733 735 740 743 746 748 750 754 765 769 771 803 820 824 829 831 833 836 838 851 856 859 862 864 870 872 874 881 883 885 888 890 892 896 899 901 903 906 908 910 912 

//Results for Data_2.txt:
//Maxima Indices:
//55 93 133 214 292 385 421 435 437 445 452 459 466 473 478 480 487 494 501 506 508 514 517 519 523 526 528 530 533 535 542 546 550 553 558 561 566 569 571 578 582 587 590 597 600 603 605 610 618 627 630 634 636 650 653 655 659 662 664 666 669 671 674 682 686 689 694 697 702 706 708 711 714 718 723 725 727 729 732 734 736 739 741 744 747 749 752 756 764 766 770 772 802 817 823 827 830 832 835 837 839 850 854 857 861 863 865 868 871 873 875 880 882 884 886 889 891 893 897 900 902 905 907 909 911 913 933 
//Minima Indices:
//16 92 94 173 260 336 413 436 444 451 458 465 472 474 477 479 481 486 493 500 502 505 507 512 516 518 520 525 527 529 532 534 538 543 547 552 555 560 567 570 585 588 594 599 601 604 607 617 629 633 635 652 654 656 661 663 665 667 670 673 675 679 683 688 691 696 703 707 709 712 716 721 724 726 728 730 733 735 740 743 746 748 750 754 765 769 771 803 820 824 829 831 833 836 838 851 856 859 862 864 870 872 874 881 883 885 888 890 892 896 899 901 903 906 908 910 912 
