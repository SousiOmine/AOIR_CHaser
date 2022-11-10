/************************************************/
/*												*/
/*	CHaserOnlineClient2020 Header				*/
/*												*/
/*	Date	2019.11.24							*/
/*												*/
/*	簡易マッピング								*/
/*	場外に出たら切断する						*/
/*												*/
/************************************************/
#include <stdio.h>

int RemakeReturnNumber19x19(int count, int mode,	int *returnNumber, int HoseiReturnNumber[19][19]);
int MapWrite(int retsu1, int gyou1, int retsu2, int gyou2, int *returnNumber, int HoseiReturnNumber[19][19]);
void MapView(int HoseiReturnNumber[19][19], int ViewMode);
int MapMove(int NewCenterRetsu, int NewCenterGyou, int HoseiReturnNumber[19][19]);
int MapInit(int retsu1, int gyou1, int retsu2, int gyou2, int InitCharNumber, int HoseiReturnNumber[19][19]);

int RemakeReturnNumber19x19(int count, int mode,	int *returnNumber, int HoseiReturnNumber[19][19]){
	
	switch(mode){	//行動によって記録方法を変える
		case 4:	//その場でgr
			switch(count){
				case 9:
					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//前回の配列と同じように場外に触れている
					break;
				
				default:
					break;
			}
			
			break;
		
		case 1:	//上に移動（wu, gru）
		case 17://pd2wu
			switch(count){
				case 9:
					MapMove(0, -1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//上側が場外
					MapMove(0, -1, HoseiReturnNumber);

					//***
					//0C2
					//345
					MapWrite(8, 9, 10, 10, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 0, 18, 8, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 3:	//左に移動（wl, grl）
		case 15://pr2wl
			switch(count){
				case 9:
					MapMove(-1, 0, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//左側が場外
					MapMove(-1, 0, HoseiReturnNumber);

					//*01
					//*C3
					//*45
					MapWrite(9, 8, 10, 10, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 0, 8, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 5:	//右に移動（wr, grr）
		case 13://pl2wr
			switch(count){
				case 9:
					MapMove(1, 0, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//右側が場外
					MapMove(1, 0, HoseiReturnNumber);

					//01*
					//2C*
					//45*
					MapWrite(8, 8, 9, 10, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(10, 0, 18, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 7:	//下に移動（wd, grd）
		case 11://pu2wd
			switch(count){
				case 9:
					MapMove(0, 1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//下側が場外
					MapMove(0, 1, HoseiReturnNumber);

					//012
					//3C5
					//***
					MapWrite(8, 8, 10, 9, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 10, 18, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 20://prd0wlu
		case 18://prd2wlu
			switch(count){
				case 9:
					MapMove(-1, -1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 22://pld0wru
		case 16://pld2wru
			switch(count){
				case 9:
					MapMove( 1, -1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 28://plu0wrd
		case 10://plu2wrd
			switch(count){
				case 9:
					MapMove( 1, 1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 26://pru0wld
		case 12://pru2wld
			switch(count){
				case 9:
					MapMove( -1, 1, HoseiReturnNumber);

					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 30://keilu
			MapMove(-1, -2, HoseiReturnNumber);
			switch(count){
				case 9:
					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 32://keiru
			MapMove(1, -2, HoseiReturnNumber);
			switch(count){
				case 9:
					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 36://keild
			MapMove(-1, 2, HoseiReturnNumber);
			switch(count){
				case 9:
					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 38://keird
			MapMove(1, 2, HoseiReturnNumber);
			switch(count){
				case 9:
					//9,9を中心に記録する
					MapWrite(8, 8, 10, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 41:	//上に移動（du）
			MapMove(0, -1, HoseiReturnNumber);
			switch(count){
				case 9:
					//012
					//345
					//678
					// C
					MapWrite(8, 6, 10, 8, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//上側が場外
					//***
					//012
					//345
					// C
					MapWrite(8, 7, 10, 8, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 0, 18, 6, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;

		case 43:	//左に移動（dl）
			MapMove(-1, 0, HoseiReturnNumber);
			switch(count){
				case 9:
					//012
					//345C
					//678
					MapWrite(6, 8, 8, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//左側が場外
					//*01
					//*23C
					//*45
					MapWrite(7, 8, 8, 10, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 0, 6, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;

		case 45:	//右に移動（dr）
			MapMove(1, 0, HoseiReturnNumber);
			switch(count){
				case 9:
					// 012
					//C345
					// 678
					MapWrite(10, 8, 12, 10, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//右側が場外
					// 01*
					//C23*
					// 45*
					MapWrite(10, 8, 11, 10, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(12, 0, 18, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;

		case 47:	//下に移動（dd）
			MapMove(0, 1, HoseiReturnNumber);
			switch(count){
				case 9:
					// C
					//012
					//345
					//678
					MapWrite(8, 10, 10, 12, returnNumber, HoseiReturnNumber);
					
					break;
				
				case 6:	//下側が場外
					// C
					//012
					//345
					//***
					MapWrite(8, 10, 10, 11, returnNumber, HoseiReturnNumber);

					//場外を記録する
					MapInit(0, 12, 18, 18, -1, HoseiReturnNumber);
					
					break;
				
				default:
					break;
			}
			
			break;

		case 51://pu3su
			MapInit(9, 8, 9, 8, 3, HoseiReturnNumber);
			MapMove(1, 0, HoseiReturnNumber);
			if(count > 0){
				MapWrite(9, 9 - count, 9, 8, returnNumber, HoseiReturnNumber);
			}

			break;

		case 53://pl3sl
			MapInit(8, 9, 8, 9, 3, HoseiReturnNumber);
			MapMove(0, -1, HoseiReturnNumber);
			if(count > 0){
				MapWrite(9 - count, 9, 8, 9, returnNumber, HoseiReturnNumber);
			}
			break;

		case 55://pr3sr
			MapInit(10, 9, 10, 9, 3, HoseiReturnNumber);
			MapMove(0, 1, HoseiReturnNumber);
			
			if(count > 0){
				MapWrite(10, 9, count + 9, 9, returnNumber, HoseiReturnNumber);
			}
			break;
		
		case 57://pd3sd
			MapInit(9, 10, 9, 10, 3, HoseiReturnNumber);
			MapMove(-1, 0, HoseiReturnNumber);
			
			if(count > 0){
				MapWrite(9, 10, 9, count + 9, returnNumber, HoseiReturnNumber);
			}
			break;
		
		default:
			break;
	}
	return 0;
}

int MapWrite(int retsu1, int gyou1, int retsu2, int gyou2, int *returnNumber, int HoseiReturnNumber[19][19]){
	int gyou, retsu;
	int ichi = 0;

	for(gyou = gyou1; gyou <= gyou2; gyou++){
		for(retsu = retsu1; retsu <= retsu2; retsu++){
			if(returnNumber[ichi] != -1){	//場外ではなければ
				HoseiReturnNumber[retsu][gyou] = returnNumber[ichi];
			}
			ichi++;
		}
	}
	//自分のクライアントを記入
	HoseiReturnNumber[9][9] = 1000;
	
	if(ichi > 0){
		return ichi;
	}
	else{
		return -1;
	}
}


int MapMove(int NewCenterRetsu, int NewCenterGyou, int HoseiReturnNumber[19][19]){
	int	MotoRetsu, MotoGyou;
	int NewRetsu, NewGyou;
	int i, j;
	int BuffReturnNumber[19][19];
	int MapCharNumber;
	
	//配列のコピー
	for(i=0; i<19; i++){
		for(j=0; j<19; j++){
			BuffReturnNumber[i][j] = HoseiReturnNumber[i][j];
		}
	}
	BuffReturnNumber[9][9] = 0;
	
	for(NewRetsu = 0; NewRetsu < 19; NewRetsu++){
		for(NewGyou = 0; NewGyou < 19; NewGyou++){
			MotoRetsu = NewRetsu + NewCenterRetsu;
			MotoGyou  = NewGyou  + NewCenterGyou;
			
			if((MotoRetsu>=0)&&(MotoGyou>=0)&&(MotoRetsu<=18)&&(MotoGyou<=18)){	//新マップの範囲内であれば移行する
				HoseiReturnNumber[NewRetsu][NewGyou] = BuffReturnNumber[MotoRetsu][MotoGyou];
			}
			else{
				HoseiReturnNumber[NewRetsu][NewGyou] = -2;
			}
		}
	}
	
	return 0;
}


int MapInit(int retsu1, int gyou1, int retsu2, int gyou2, int InitCharNumber, int HoseiReturnNumber[19][19]){
	int gyou, retsu;
	int count = -1;
	
	for(gyou = gyou1; gyou <= gyou2; gyou++){
		for(retsu = retsu1; retsu <= retsu2; retsu++){
			HoseiReturnNumber[retsu][gyou] = InitCharNumber;
			count++;
		}
	}
	
	return count;
}


void MapView(int HoseiReturnNumber[19][19], int ViewMode){
	int gyou, retsu;
	char Num2char[70] = " @X* TTTTt  o       WWWW      wwww      gggg      GGGG      BBBB";
					//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
					//	 0         1         2         3         4         5         6         7         8         9
	char ClientChar[10] = " CHaserOn";
	int MapCharNumber;
	
	printf("\n");
	printf("Mapping:\n");	//debug
	for(gyou = 0; gyou < 19; gyou++){
		printf("Mapping:");	//debug
		
		for(retsu = 0; retsu < 19; retsu++){
			MapCharNumber = HoseiReturnNumber[retsu][gyou];
			if(MapCharNumber>=1000){
				//クライアントキャラの表示
				printf("%c", ClientChar[MapCharNumber/1000]);
			}
			else if(MapCharNumber==-2){
				//不明地
				printf("#");
			}
			else if(MapCharNumber==-1){
				//場外
				printf("O");
			}
			else{
				//マップキャラの表示
				printf("%c", Num2char[MapCharNumber]);
			}
		}
		if(ViewMode != 1){
			printf("\x1b[K");
		}
		printf("\n");
	}
}


