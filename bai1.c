#include<stdio.h>
#include<stdint.h>

typedef enum{
    AO          = 1 << 0,   //0b00000001/
    QUAN        = 1 << 1,   //0b00000010/
    VAY         = 1 << 2,   //0b00000100
    DAM         = 1 << 3,   //0b00001000
    NHAN        = 1 << 4,   //0b00010000 /
    VONG_TAY    = 1 << 5,   //0b00100000
    GIAY        = 1 << 6,   //0b01000000/
    TUI         = 1 << 7    //0b10000000
}DoDungCaNhan;

void Them_Vao_Gio_Hang(uint8_t *gio_hang, DoDungCaNhan ten_do_dung){
    *gio_hang |= ten_do_dung;
}

void Xoa_Khoi_Gio_Hang(uint8_t *gio_hang, DoDungCaNhan ten_do_dung){
    *gio_hang &= ~ten_do_dung;
}

void Kiem_Tra_San_Pham(uint8_t *gio_hang, DoDungCaNhan ten_do_dung){
    uint8_t ao_mask = 1;
    uint8_t quan_mask = 2;
    uint8_t vay_mask = 4;
    uint8_t dam_mask = 8;
    uint8_t nhan_mask = 16;
    uint8_t vong_tay_mask = 32;
    uint8_t giay_mask = 64;
    uint8_t tui_mask = 128;
    
    printf("Kiem Tra: \t");
    if((*gio_hang & ten_do_dung) == 1) printf("Co Ao\n");
    else if((*gio_hang & ten_do_dung) == 2) printf("Co Quan\n");
    else if((*gio_hang & ten_do_dung) == 4) printf("Co Vay\n");
    else if((*gio_hang & ten_do_dung) == 8) printf("Co Dam\n");
    else if((*gio_hang & ten_do_dung) == 16) printf("Co Nhan\n");
    else if((*gio_hang & ten_do_dung) == 32) printf("Co Vong tay\n");
    else if((*gio_hang & ten_do_dung) == 64) printf("Co Giay\n");
    else if((*gio_hang & ten_do_dung) == 128) printf("Co Tui\n");
    else printf("Khong co\n");

}

void Hien_Thi_Gio_Hang(uint8_t *gio_hang){
    uint8_t ao_mask = 1;
    uint8_t quan_mask = 2;
    uint8_t vay_mask = 4;
    uint8_t dam_mask = 8;
    uint8_t nhan_mask = 16;
    uint8_t vong_tay_mask = 32;
    uint8_t giay_mask = 64;
    uint8_t tui_mask = 128;

    printf("Gio Hang Hien Co: ");
    if((*gio_hang & ao_mask) == 1) printf("Ao\t");
    if((*gio_hang & quan_mask) == 2) printf("Quan\t");
    if((*gio_hang & vay_mask) == 4) printf("Vay\t");
    if((*gio_hang & dam_mask) == 8) printf("Dam\t");
    if((*gio_hang & nhan_mask) == 16) printf("Nhan\t");
    if((*gio_hang & vong_tay_mask) == 32) printf("Vong tay\t");
    if((*gio_hang & giay_mask) == 64) printf("Giay\t");
    if((*gio_hang & tui_mask) == 128) printf("Tui\t");
}



int main(int argc, char const *argv[])
{
    uint8_t GIO_HANG;
    DoDungCaNhan ten_do_dung = AO|QUAN|VAY|DAM|NHAN|GIAY;

    Them_Vao_Gio_Hang(&GIO_HANG, ten_do_dung);
    printf("GIO HANG DA THEM: %d\n", GIO_HANG);

    //Xoa_Khoi_Gio_Hang(&GIO_HANG, NHAN);
    printf("GIO HANG SAU KHI XOA: %d\n", GIO_HANG);

    Kiem_Tra_San_Pham(&GIO_HANG, GIAY);
    Kiem_Tra_San_Pham(&GIO_HANG, QUAN);

    Hien_Thi_Gio_Hang(&GIO_HANG);
    return 0;
}

