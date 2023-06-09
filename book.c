/************************************************
 * book.c -- xây dựng cơ sở giá trị sách cho 
 *      chương trình PBL 
 * 
 * PURPOSE: 
 *      1. tạo cơ sở giá trị sách -> qua đó tạo cơ sở 
 *          giá trị danh sách sách (cơ sở giá trị chính)
 * 
 *      2. tạo giá trị sách và 2 hàm cơ bản của giá trị 
 *          sách 
 * 
 * STATUS: code hoàn thành
 * 
 * SOURCE: PBL lập trình 
 * 
*/

// #include "setting.h"
#include "int_to_string.c"
#include <stdlib.h>
#include <string.h>
#include "input_file.c"



struct book {
    char* isbn; /* book id */
    char* name; /* name of book */
    char* author; /* author of book */
    char* publisher; /* publisher of book */
    int publish_year; /* publish year of book */
    int reprint; /* number of times of reprint */
    int num_pages; /* number of pages */
    int cost; /* cost of book */
    int quantity; /* quantity of book */
}; 

typedef struct book book; 

/*******************************************************
 * book_template -- hàm tạo giá trị mẫu để gán vào biến 
 *      loại sách 
 *  
*/
book book_template(const char* isbnV, const char* nameV, const char* authorV, const char* publisherV, int publish_yearV, int reprintV, int num_pagesV, int costV, int quantityV) {
    book result; 

    result.isbn = (char*)malloc(MAX_LENGTH); 
    result.name = (char*)malloc(MAX_LENGTH);
    result.author = (char*)malloc(MAX_LENGTH);
    result.publisher = (char*)malloc(MAX_LENGTH);

    strcpy(result.isbn, isbnV); 
    strcpy(result.name, nameV); 
    strcpy(result.author, authorV); 
    strcpy(result.publisher, publisherV); 
    // result.isbn = isbnV; 
    // result.name = nameV; 
    // result.author = authorV;
    // result.publisher = publisherV; 
    result.publish_year = publish_yearV ;
    result.reprint = reprintV; 
    result.num_pages = num_pagesV; 
    result.cost = costV; 
    result.quantity = quantityV; 

    #ifdef DEBUG5 
        printf("Book:\nIsbn: %s\nName: %s\nAuthor: %s\nPublisher: %s\nPublish year: %d\nReprint: %d times\nPages: %d\nCost: %d$\nQuantity: %d.\n",
        result.isbn, result.name, result.author, result.publisher, result.publish_year, result.reprint, result.num_pages, result.cost, result.quantity); 
    #endif

    return result; 
}

/*************************************************
 * book_to_string -- hàm để minh họa giá trị của giá 
 *      trị loại sách bằng xâu kí tự 
 *  
*/
char* book_to_string(book bookV) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    strcpy(result, "---------BOOK--------\nISBN: "); 
    strcat(result, bookV.isbn); 
    strcat(result, "\nName: "); 
    strcat(result, bookV.name); 
    strcat(result, "\nAuthor: "); 
    strcat(result, bookV.author);
    strcat(result, "\nPublisher: "); 
    strcat(result, bookV.publisher); 
    strcat(result, "\nPublish year: "); 
    strcat(result, itos(bookV.publish_year)); 
    strcat(result, "\nReprint: "); 
    strcat(result, itos(bookV.reprint)); 
    strcat(result, " times\nPages: "); 
    strcat(result, itos(bookV.num_pages)); 
    strcat(result, "\nCost: "); 
    strcat(result, itos(bookV.cost)); 
    strcat(result, "$\nQuantity: "); 
    strcat(result, itos(bookV.quantity)); 
    strcat(result, "\n---------------------\n"); 

    #ifdef DEBUG5
    {
        printf("%s", result); 
    }
    #endif

    return result; 
}

/******************************************************
 * book_template_by_file -- nhạp giá trị cho giá trị sách 
 *      bằng dòng trong file 
 * 
*/
book book_template_by_file_line(const char* file_name, int lineV) {
    book result; 

    result.isbn = (char*)malloc(MAX_LENGTH); 
    result.name = (char*)malloc(MAX_LENGTH);
    result.author = (char*)malloc(MAX_LENGTH);
    result.publisher = (char*)malloc(MAX_LENGTH);

    sscanf(content_line_file(file_name, lineV), "%[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %d,%d,%d,%d,%d", result.isbn, result.name, result.author, result.publisher, &result.publish_year, &result.reprint, &result.num_pages, &result.cost, &result.quantity); 

    #ifdef DEBUG4
        printf("%s", book_to_string(result)); 
    #endif 

    return result; 
}


#ifdef DEBUG4

int main(void) {
    book Sherlock_Holmes_pt1; 

    Sherlock_Holmes_pt1 = book_template_by_file_line("book_list_file.csv", 2); 

}

#endif

