#include <iostream>
#include <algorithm>

using namespace std;

class QuanLySucKhoe {
private:
    // ==========================================
    // CÁC PHUONG THUC TINH
    // ==========================================
    int phanLoaiChieuCaoNam(float h) {
        if (h >= 160) return 1;
        if (h >= 156) return 2;
        if (h >= 152) return 3;
        if (h >= 149) return 4;
        return 5;
    }

    int phanLoaiCanNangNam(float w) {
        if (w >= 48) return 1;
        if (w >= 46) return 2;
        if (w >= 42) return 3;
        if (w >= 39) return 4;
        return 5;
    }

    int phanLoaiChieuCaoNu(float h) {
        if (h >= 152) return 1;
        if (h >= 149) return 2;
        if (h >= 145) return 3;
        if (h >= 142) return 4;
        return 5;
    }

    int phanLoaiCanNangNu(float w) {
        if (w >= 44) return 1;
        if (w >= 42) return 2;
        if (w >= 40) return 3;
        if (w >= 37) return 4;
        return 5;
    }

public:
    // ==========================================
    // CÁC PHUONG THUC CHINH
    // ==========================================
    void danhGiaTheLuc() {
        int gioi_tinh;
        float chieu_cao, can_nang;
        
        cout << "\n--- DANH GIA TIEU CHUAN THE LUC SINH VIEN HPU2 ---\n";
        cout << "Chon gioi tinh (1 - Nam, 2 - Nu): ";
        cin >> gioi_tinh;
        
        if (gioi_tinh != 1 && gioi_tinh != 2) {
            cout << "Gioi tinh khong hop le!\n";
            return;
        }

        cout << "Nhap chieu cao (cm, vd 165): ";
        cin >> chieu_cao;
        cout << "Nhap can nang (kg, vd 55): ";
        cin >> can_nang;

        if (chieu_cao <= 0 || can_nang <= 0) {
            cout << "So lieu khong hop le!\n";
            return;
        }

        int loaiChieuCao, loaiCanNang;
        if (gioi_tinh == 1) { 
            loaiChieuCao = phanLoaiChieuCaoNam(chieu_cao);
            loaiCanNang = phanLoaiCanNangNam(can_nang);
        } else { 
            loaiChieuCao = phanLoaiChieuCaoNu(chieu_cao);
            loaiCanNang = phanLoaiCanNangNu(can_nang);
        }

        int loaiTheLuc = max(loaiChieuCao, loaiCanNang);
        cout << "\n=> KET QUA PHAN LOAI THE LUC: LOAI " ;
        switch(loaiTheLuc) {
            case 1: cout << "I (Rat khoe)\n"; break;
            case 2: cout << "II (Khoe)\n"; break;
            case 3: cout << "III (Trung binh)\n"; break;
            case 4: cout << "IV (Yeu)\n"; break;
            case 5: cout << "V (Rat yeu)\n"; break;
        }
    }

    void danhGiaVanDong() {
        int so_buoc, phut_vua, phut_manh, ngay_co;
        cout << "\n--- CHI SO VAN DONG THE CHAT (WHO) ---\n";
        cout << "Trung binh ban di bao nhieu buoc 1 ngay? "; cin >> so_buoc;
        cout << "So phut tap the duc muc do VUA moi Tuan (vd: di bo nhanh, dap xe...)? "; cin >> phut_vua;
        cout << "So phut tap the duc muc do MANH moi Tuan (vd: chay bo, da bong...)? "; cin >> phut_manh;
        cout << "So ngay tap tang cuong co bap moi Tuan (vd: hit dat, gym...)? "; cin >> ngay_co;
        
        cout << "\n--- KET QUA DANH GIA VAN DONG ---\n";
        if (so_buoc >= 7000 && so_buoc <= 10000) cout << "- So buoc chan: Dat chuan (Giam tac hai ngoi nhieu).\n";
        else if (so_buoc > 10000) cout << "- So buoc chan: Rat tot, ban rat nang dong!\n";
        else cout << "- So buoc chan: Chua dat. (Muc tieu: 7000 - 10000 buoc/ngay).\n";
        
        if (phut_vua >= 150 || phut_manh >= 75) cout << "- Thoi luong van dong: Dat tieu chuan cua WHO.\n";
        else cout << "- Thoi luong van dong: Thieu. (Can 150p vua hoac 75p manh moi Tuan).\n";
        
        if (ngay_co >= 2) cout << "- Tap co bap: Dat chuan (>= 2 ngay/tuan).\n";
        else cout << "- Tap co bap: Nen bo sung cac bai tap co bap it nhat 2 ngay/tuan.\n";
        cout << "*Loi khuyen: Han che ngoi lien tuc qua lau, hay dung day vuon vai sau moi 45-60 phut.\n";
    }

    void danhGiaNuocUong() {
        float can_nang, nuoc_uong, phut_the_thao;
        cout << "\n--- CHI SO LUONG NUOC UONG ---\n";
        cout << "Nhap can nang cua ban (kg): "; cin >> can_nang;
        cout << "Thoi gian tap the thao moi ngay (phut): "; cin >> phut_the_thao;
        cout << "Ban hien uong bao nhieu lit nuoc 1 ngay? (vd: 1.5): "; cin >> nuoc_uong;
        
        // Tinh toan nuoc khuyen nghi
        float nuoc_co_ban = can_nang * 0.035; // 35ml / kg
        float nuoc_bo_sung = (phut_the_thao / 30.0) * 0.4; // Trung binh 400ml cho 30 phut tap
        float tong_nuoc_can = nuoc_co_ban + nuoc_bo_sung;
        
        cout << "\n--- KET QUA DANH GIA NUOC UONG ---\n";
        cout << "=> Luong nuoc co the ban can moi ngay: Khoang " << tong_nuoc_can << " lit.\n";
        if (nuoc_uong >= tong_nuoc_can) {
            cout << "=> Danh gia: Ban da uong du luong nuoc can thiet!\n";
        } else {
            cout << "=> Danh gia: Ban dang uong thieu khoang " << tong_nuoc_can - nuoc_uong << " lit nuoc.\n";
        }
        cout << "*Dau hieu du nuoc: Nuoc tieu co mau vang nhat/trong suot, di tieu 5-7 lan/ngay.\n";
    }

    void danhGiaGiacNgu() {
        float gio_ngu, phut_ngu_trua, thoi_gian_chim_vao_giac_ngu;
        int gio_len_giuong;
        
        cout << "\n--- CHI SO GIAC NGU (HIEP HOI GIAC NGU QUOC GIA) ---\n";
        cout << "Ban thuong ngu may tieng moi dem? (vd 7.5): "; cin >> gio_ngu;
        cout << "Ban thuong bat dau ngu vao luc may gio? (Nhap so gio 0-23, vd: 23): "; cin >> gio_len_giuong;
        cout << "Thoi gian ban de vao giac ngu la bao lau? (phut, vd: 15): "; cin >> thoi_gian_chim_vao_giac_ngu;
        cout << "Ban ngu trua bao lau? (phut, neu khong ngu nhap 0): "; cin >> phut_ngu_trua;
        
        cout << "\n--- KET QUA DANH GIA GIAC NGU ---\n";
        if (gio_ngu >= 7 && gio_ngu <= 9) cout << "- Thoi luong ngu: Ban co thoi luong ngu ly tuong (7-9 tieng) cho do tuoi sinh vien.\n";
        else cout << "- Thoi luong ngu: Chua tot. Nguy co giam tap trung neu ngu duoi 6 tieng hoac tren 10 tieng.\n";
        
        if (gio_len_giuong >= 22 && gio_len_giuong <= 23) cout << "- Khung gio ngu: Ban di ngu vao khung gio vang, rat tot cho nhip sinh hoc!\n";
        else cout << "- Khung gio ngu: Ban dang thuc khuya hoac ngu qua som. (Khuyen nghi: 22h00 - 23h30).\n";
        
        if (thoi_gian_chim_vao_giac_ngu <= 20) cout << "- Chat luong: De chim vao giac ngu (<= 20 phut), he than kinh khoe manh.\n";
        else cout << "- Chat luong: Kho vao giac ngu, can thu gian hoac han che thiet bi dien tu truoc khi ngu.\n";
        
        if (phut_ngu_trua == 0) cout << "- Ngu trua: Ban khong ngu trua. Co the chop mat 15-30p neu thay met.\n";
        else if (phut_ngu_trua >= 15 && phut_ngu_trua <= 30) cout << "- Ngu trua: Hop ly. Giup phuc hoi ma khong gay kho ngu ban dem.\n";
        else cout << "- Ngu trua: Ban ngu trua qua nhieu. Khuyen nghi chi 15-30 phut.\n";
    }

    void menuDanhGiaSinhHoat() {
        int lua_chon;
        do {
            cout << "\n=========================================\n";
            cout << "  DANH GIA THOI QUEN SINH HOAT HANG NGAY   \n";
            cout << "=========================================\n";
            cout << "1. Danh gia Van dong the chat\n";
            cout << "2. Danh gia Luong nuoc uong\n";
            cout << "3. Danh gia Chat luong giac ngu\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "Moi ban chon (0-3): ";
            cin >> lua_chon;
            
            switch (lua_chon) {
                case 1: danhGiaVanDong(); break;
                case 2: danhGiaNuocUong(); break;
                case 3: danhGiaGiacNgu(); break;
                case 0: break;
                default: cout << "Lua chon khong hop le!\n";
            }
        } while (lua_chon != 0);
    }

    void chayChuongTrinh() {
        int lua_chon_menu;

        do {
            cout << "\n=========================================\n";
            cout << "   QUAN LY SUC KHOE SINH VIEN - HPU2     \n";
            cout << "=========================================\n";
            cout << "1. Danh gia The luc (Theo Bo Y Te)\n";
            cout << "2. Danh gia Thoi quen Sinh hoat (Van dong, uong nuoc, giac ngu)\n";
            cout << "0. Thoat chuong trinh\n";
            cout << "Moi ban chon chuc nang (0-2): ";
            cin >> lua_chon_menu;

            switch (lua_chon_menu) {
                case 1:
                    danhGiaTheLuc();
                    break;
                case 2:
                    menuDanhGiaSinhHoat();
                    break;
                case 0:
                    cout << "\nCam on ban da su dung ung dung cua HPU2. Tam biet!\n";
                    break;
                default:
                    cout << "\nLua chon khong hop le, vui long chon lai tu 0 den 2!\n";
            }
        } while (lua_chon_menu != 0);
    }
};

// ==========================================
// HAM MAIN SACH SE HON NHO OOP
// ==========================================
int main() {
    // Tao mot doi tuong tu lop QuanLySucKhoe
    QuanLySucKhoe heThong; 
    
    // Goi phuong thuc chay chuong trinh
    heThong.chayChuongTrinh(); 

    return 0;
}
