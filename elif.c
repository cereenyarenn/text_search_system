void dosyadaKelimeAra(const char*girdiDosyaAdi, const char*ciktiDosyaAdi,const char*aranacakKelime){
    FILE *girdiDosya= fopen(girdiDosyaAdi,"r");
    FILE *ciktiDosya= fopen(ciktiDosyaAdi,"w");

    //dosya acilma kontrolu yapıyoruz.
    if(girdiDosya==NULL){
        printf("HATA: %s dosyasi acilamadi. Dosyanin varligindan emin olun.\n",girdiDosyaAdi);
        return ;
    }
    if(ciktiDosya==NULL){
        printf("HATA: %s sonuc dosyasi olusturulamadi.\n",ciktiDosyaAdi);
        fclose(girdiDosya);
        return ;
    }

    //rapor basligi yazdırma
}