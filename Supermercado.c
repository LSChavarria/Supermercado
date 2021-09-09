#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define IVA 0.16

int recuperarusuarios();
int recuperarclientes();
int recuperarproductos();
int recuperartipoproductos();
int recuperarpedido();
int recuperarpedidodetalle();
int submenu();
int submenuproductos();
int submenupedidoventa();
int vusuario(char usuario[6]);
int vpassword(char password[8]);
int vnameusuario(char name[50]);
int vnamecliente(char name[50]);
int vnameproducto(char name[50]);
int vnametipoproducto(char name[50]);
int tel(char tel[50]);
int vtipo(int tipo);
long generaridusuario(int i);
long generaridcliente(int i);
long generaridproducto(int i);
long generaridtipoproducto(int i);
long generaridpedido(int i);
long generaridpedidodetalle(int i);
int nameexistuser(char name[50]);
int nameexistcliente(char name[50]);
int nameexistproducto(char name[50]);
int nameexisttipoproducto(char name[50]);
int idexistcliente(long id);
int idexistproduct(long id);
int validarnumero();
int idexisttipeproduct(long id);   
void fechaimpresion();
void fechaimpresion2();   
int login();
void actualizarusuarios(int i6);
void actualizarclientes(int i1);
void actualizarproductos(int i2);
void actualizartipoproducto(int i3);
void actualizarpedido(int i4);
int espacios(char name[50]);
char reus[10];
int power;
struct registrocliente{
	char name[50],calle[50],colonia[50],numcasa[20],telefono[20];
	int estatus;
	long id;
}client[100];

struct registrousuario{
	long id;
	char usuario[7],password[9],name[50];
	int estatus,tipo;
}user[100];

struct registroproducto{
	char name[50];
	int numexistencia;
	float precio;
	int estatus;
	long id;
	long idtipo;
	char tipo[50];
}product[100];

struct ac{
    char user[10];
	char pass[10];
};

struct registrotipodeproducto{
	char name[50];
	long id;
	int estatus;
}tipeproduct[100];

struct registropedidoventa{
	long idpedido;
	int npedido;
	long idcliente;
 	char fechapedido[50];
	char fechaentrega[50];
	int d,m,a;
	double subtotal;
	double iva;
	double total;
	int eatatus;
}order[100];

struct registropedidodetalle{
	long idpedidodet;
	long idpedido;
	long idproducto;
	long cantidad;
	double precio;
}orderdetail[100];

int main(){
	
	char f[10],fe[10];
	FILE *fecha;
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%y",tlocal);
	fecha=fopen("Fecha.txt","w");
	fprintf(fecha,"%s\n",output);
	fclose(fecha);
	if((fecha=fopen("Fecha.txt","r"))==NULL) printf("No se pudo abrir\n\n");
	else{
		while(!feof(fecha)){
			fscanf(fecha,"%s",f);		
		}
	}
fclose(fecha);
	
	FILE *cliente,*producto,*tipoproducto,*pedido,*pedidodet,*usuario,*REG;
	
	int cont =0;
	double total;																	
	int ncantidad;																	//ncantidad es para sumarla cantidad que se surtio a la canticad existente
	long codigo;																	//codigo es una variable para guardar el id del producto resurtido
	int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,tp=0,num,us;									//contadores para especificar en que espacio de la estructura se guardaran 
	char name[50];																	//variable para guardar el nombre de quien se desea buscar
	int z=0,z1=0,z2=0,z3=0,z4=0,z5=0; 												//contadores para los ciclos whiles
	int op,i,j,k,x,y,w,contvalidador=0;												//variable para guardar el numero de la opcion que se desea ejecutar
	int d1,d2,m1,m2,a1,a2;															//variables para guardar dos fechas diferentes
	
	i6=recuperarusuario();
	i1=recuperarclientes();															//estas funciones recuperan los datos de los archivos en caso de que existan
	i2=recuperarproductos();
	i3=recuperartipoproductos();
	i4=recuperarpedido();
	i5=recuperarpedidodetalle();
	while(tp==0){
		us = login();
		if(us!=0) tp=1;
		cont++;
		if(cont==3){
			printf("\n\aContacte con el administrador\n");
			exit(-1);
		}
	}
	system("pause");
	system("cls");
	printf("Buen d%ca ",161);
	while(z==0){ 		
	printf("%s \n ",reus);			
						for(i=0;i<100;i++){
		if(strcmp(reus,user[i].usuario)==0) break;
	}
	power=user[i].tipo;	
	printf("%d",power);	//while para mostrar el menu hasta que se dese cerrar el programa
		printf("\n\t\tMen%c principal\n\n1. Registro de Usuarios\n2. Registro de Clientes\n3. Registro de Productos\n4. Registro Tipo de Producto\n5. Pedido/Venta\n6. Historial Pedido/Venta\n7. Reporte Inventario\n8. Salir",163);
		op = validarnumero();
		system("cls");
		switch(op){
	
			case 1: if(power==1){													//estos if son utilizdos para validar que solo el administrador pueda entrar a las diferentes opciones a las que solo el tiene acceso
				while(z1==0){														//while para mostrar el menu hasta que se dese volver al menu principal
					printf("\n\n\t\tRegistro de Usuarios\n");
					op=submenu();
					switch(op){
						case 1:
							user[i6].id=generaridusuario(i6);
							printf("Id para este Usuario: %ld\n\n",user[i6].id);
							printf("Por favor ingrese los siguientes datos sobre el usuario:\n\n");
							while(contvalidador==0){								//Estos ciclos son usados para validar que el dato pedido sea valido
								printf("Usuario: ");
								fflush(stdin);
								gets(user[i6].usuario);
								i=vusuario(user[i6].usuario);
								if(i==1) contvalidador=1;
							}
							contvalidador=0;
							while(contvalidador==0){
								printf("Password: ");
								fflush(stdin);
								gets(user[i6].password);
								i=vpassword(user[i6].password);
								if(i==1) contvalidador=1;
							}	
							contvalidador=0;
							while(contvalidador==0){
							printf("Nombre: ");
							fflush(stdin);
							gets(user[i6].name);
							i= vnameusuario(user[i6].name);
							if(i==1) contvalidador=1;
							}
							contvalidador=0;
							while(contvalidador==0){
								printf("Tipo de cuenta \n1.-Administrador \n2.-Cajero:\n" );
								scanf("%d",&user[i6].tipo);
								i= vtipo(user[i6].tipo);
								if(i==1) contvalidador=1;
							}
							contvalidador=0;
								int i;
								i = i6;
								struct ac reg[100];
								fflush(stdin);
								REG = fopen("Registro.bin","a+b");
								if (REG == NULL){printf("ERROR 404");
								return 16;
								}			
								strcpy(reg[i6].user, user[i6].usuario);
								strcpy(reg[i6].pass, user[i6].password);
	  							fwrite(&reg[i6],sizeof(struct ac),1,REG);
								fclose(REG);
							user[i6].estatus=1;
							usuario=fopen("Usuario.txt","a");
							fprintf(usuario,"%lu\t%s\t%s %s\t%d ",user[i6].id,user[i6].usuario,user[i6].password,user[i6].name,user[i6].tipo);					//Estos son utilizados para imprimir los diferentes tipos de datos en su respectivo archivo
							fprintf(usuario,"Activo\n");
							fclose(usuario);
							i6++;
							break;
						case 2:
							printf("Ingresa el nombre del usuario: ");
							fflush(stdin);
							gets(name);
							for(i=0;i<100;i++){								//Estos for son utilizados para buscar el lugar de la estructura en el que estan guardados los datos necesarios
								if(strcmp(name,user[i].name)==0) break;
							}
							if(user[i].estatus==0) printf("Este usuario ya esta dado de baja o no existe\n");
							else user[i].estatus=0;
							break;
						case 3:
							printf("Ingresa el nombre: ");
							fflush(stdin);
							gets(name);
							i=nameexistuser(name);
							if(i==1){
								for(i=0;i<100;i++){
									if(strcmp(name,user[i].name)==0) break;
								}
								printf("Id: %lu\nUsuario: %s\nNombre: %s\n",user[i].id,user[i].usuario,user[i].name);
								if(user[i].tipo==1) printf("Tipo: Administrador\n");
								else printf("Tipo: Cajero\n");
								if(user[i].estatus==1) printf("Estatus: Activo\n\n");
								else printf("Estatus: Inactivo\n\n");
							}
							else printf("Este nombre no esta registrado\n");
							break;
						case 4:
							z1=1;
							break;
						default:
							printf("Opcion invalida!!!\n\n"); 
					}
					system("pause");
					system("cls");	
				}
				z1=0;
				actualizarusuarios(i6);
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 2:
				if(power==1){
				while(z2==0){														//while para mostrar el menu hasta que se dese volver al menu principal
					printf("\n\n\t\tRegistro de Clientes\n");
					op=submenu();
					switch(op){
						case 1:
							client[i1].id=generaridcliente(i1);
							printf("Id para este cliente: %ld\n\n",client[i1].id);
							printf("Por favor ingrese los siguientes datos sobre el cliente:\n\n");
							while(contvalidador==0){
								printf("Nombre: ");
								fflush(stdin);
								gets(client[i1].name);
								i=vnamecliente(client[i1].name);
								if(i==1) contvalidador=1;
							}
							contvalidador=0;
							printf("Calle: ");
							fflush(stdin);
							gets(client[i1].calle);
							printf("Colonia: ");
							fflush(stdin);
							gets(client[i1].colonia);
							printf("N%cmero de casa: ",163);
							fflush(stdin);
							gets(client[i1].numcasa);
							while(contvalidador==0){
								printf("N%cmero de telefono: ",163);
								fflush(stdin);
								gets(client[i1].telefono);
								i=vtel(client[i1].telefono);
								if(i==1) contvalidador=1;
							}
							contvalidador=0;
							client[i1].estatus=1;
							cliente=fopen("Cliente.txt","a");
							fprintf(cliente,"%lu\t%s\t%s\t%s\t%s\t%s\t",client[i1].id,client[i1].name,client[i1].calle,client[i1].colonia,client[i1].numcasa,client[i1].telefono);
							fprintf(cliente,"Activo\n");
							fclose(cliente);
							i1++;
							break;
						case 2:
							printf("Ingresa el nombre del cliente: ");
							fflush(stdin);
							gets(name);
							for(i=0;i<100;i++){
								if(strcmp(name,client[i].name)==0) break;
							}
							if(client[i].estatus==0) printf("Esta cuenta ya esta dada de baja o no existe\n");
							else client[i].estatus=0;
							break;																	
						case 3:
							printf("Ingresa el nombre: ");
							fflush(stdin);
							gets(name);
							i=nameexistcliente(name);
							if(i==1){
								for(i=0;i<100;i++){
									if(strcmp(name,client[i].name)==0) break;
								}
								printf("Id Cliente: %lu\nNombre: %s\nCalle: %s\nColonia: %s\nN%cmero de casa: %s\nTelefono: %s\n",client[i].id,client[i].name,client[i].calle,client[i].colonia,163,client[i].numcasa,client[i].telefono);
								if(client[i].estatus==1) printf("Estatus: Activo\n\n");
								else printf("Estatus: Inactivo\n\n");
							}
							else printf("Este nombre no esta registrado\n");
							break;								
						case 4:
							z2=1;
							break;
						default:
							printf("Opcion invalida!!!\n\n"); 
					}
					system("pause");
					system("cls");	
				}
				z2=0;
				actualizarclientes(i1);
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 3:
				if(power==1){
				while(z3==0){														//while para mostrar el menu hasta que se dese volver al menu principal
					printf("\n\n\t\tRegistro de Productos\n");
					op=submenuproductos();
					switch(op){
						case 1:
							if(i3>=0){
								product[i2].id=generaridproducto(i2);
								printf("Id para este producto: %lu\n\n",product[i2].id);
								printf("Por favor ingresa los siguientes datos sobre el producto:\n\n");
								while(contvalidador==0){
									printf("Ingresa el nombre del tipo de producto que es este articulo: ");
									fflush(stdin);
									gets(product[i2].tipo);
									i=nameexisttipoproducto(product[i2].tipo);
									if(i==1) contvalidador=1;
								}
								for(i=0;i<100;i++){
									if(strcmp(product[i2].tipo,tipeproduct[i].name)==0) product[i2].idtipo=tipeproduct[i].id;
								}
								contvalidador=0;
								while(contvalidador==0){
									printf("Nombre: ");
									fflush(stdin);
									gets(product[i2].name);
									i=vnameproducto(product[i2].name);
									if(i==0) contvalidador=1;
								}
								contvalidador=0;
								printf("N%cmero en existencia: ",163);
								scanf("%d",&product[i2].numexistencia);
								printf("Precio:");
								scanf("%f",&product[i2].precio);
								product[i2].estatus=1;
								producto=fopen("Producto.txt","a");
								fprintf(producto,"%lu\t%s\t%lu\t%d\t%.2f\tActivo\n",product[i2].id,product[i2].name,product[i2].idtipo,product[i2].numexistencia,product[i2].precio);
								fclose(producto);
								i2++;
							}
							else printf("No has registrado ningun Tipo de Producto\n\n");
							break;
						case 2:
							printf("Ingresa el nombre del producto: ");
							fflush(stdin);
							gets(name);
							for(i=0;i<100;i++){
								if(strcmp(name,product[i].name)==0) break;
							}
							if(product[i].estatus==0) printf("Este producto ya esta dada de baja o no existe\n");
							else product[i].estatus=0;
							break;
						case 3:
							printf("Ingresa el nombre del producto: ");
							fflush(stdin);
							gets(name);
							i=nameexistproducto(name);
							if(i==1){
								for(i=0;i<100;i++){
									if(strcmp(name,product[i].name)==0) break;
								}
								printf("Id Producto: %lu\nNombre del Producto: %s\nId Tipo de Producto: %lu\nCantidad en existencia: %d\nPrecio: %.2f\n",product[i].id,product[i].name,product[i].idtipo,product[i].numexistencia,product[i].precio);
								if(product[i].estatus==1) printf("Estatus: Activo\n\n");
								else printf("Estatus: Inactivo\n\n");
							}
							else printf("Este nombre no esta registrado\n");
							break;
						case 4:
							while(contvalidador==0){
								printf("Ingresa el codigo del producto: ");
								scanf("%lu",&codigo);
								for(i=0;i<100;i++){
									if(codigo==product[i].id){
										contvalidador=1;
										break;
									} 
								}
							}
							contvalidador=0;
							printf("Ingrese la cantidad que llego: ");
							scanf("%d",&ncantidad);
							product[i].numexistencia=product[i].numexistencia+ncantidad;
							printf("Cantidad en existencia actualizada: %d\n",product[i].numexistencia);
							break;
						case 5:
							z3=1;
							break;
						default:
							printf("Opcion invalida!!!\n\n"); 
					}
					system("pause");
					system("cls");	
				}
				z3=0;
				actualizarproductos(i2);
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 4:
				if(power==1){
				while(z4==0){														//while para mostrar el menu hasta que se dese volver al menu principal
					printf("\n\n\t\tRegistro de Tipo de Producto\n");
					op=submenu();
					switch(op){
						case 1:
							tipeproduct[i3].id=generaridtipoproducto(i3);
							printf("Id para este Tipo de Producto: %lu\n\n",tipeproduct[i3].id);
							printf("Por favor ingresa el los datos que te solicitemos sobre el Tipo de producto a registrar:\n\n");
							while(contvalidador==0){
								printf("Nombre: ");
								fflush(stdin);
								gets(tipeproduct[i3].name);
								i=vnametipoproducto(tipeproduct[i3].name);
								if(i==0) contvalidador=1;
							}
							contvalidador=0;
							tipeproduct[i3].estatus=1;
							tipoproducto=fopen("Tipo_Producto.txt","a");
							fprintf(tipoproducto,"%lu\t%s\t",tipeproduct[i3].id,tipeproduct[i3].name);
							fprintf(tipoproducto,"Activo\n");
							fclose(tipoproducto);
							i3++;
							break;
						case 2:
							printf("Ingresa el nombre del producto: ");
							fflush(stdin);
							gets(name);
							for(i=0;i<100;i++){
								if(strcmp(name,tipeproduct[i].name)==0) break;
							}
							if(tipeproduct[i].estatus==0) printf("Este tipo de producto ya esta dada de baja o no existe\n");
							else tipeproduct[i].estatus=0;
							break;
						case 3:
							printf("Ingresa el nombre del Tipo de producto: ");
							fflush(stdin);
							gets(name);
							i=nameexisttipoproducto(name);
							if(i==1){
								for(i=0;i<100;i++){
									if(strcmp(name,tipeproduct[i].name)==0) break;
								}
								printf("Id Tipo de Producto: %lu\nNombre del Tipo de Producto: %s\n",tipeproduct[i].id,tipeproduct[i].name);
								if(tipeproduct[i].estatus==1) printf("Estatus: Activo\n\n");
								else printf("Estatus: Inactivo\n\n");
							}
							else printf("Este nombre no esta registrado\n");
							break;
						case 4:
							z4=1;
							break;
						default:
							printf("Opcion invalida!!!\n\n"); 
					}
					system("pause");
					system("cls");
				}
				z4=0;
				actualizartipoproducto(i3);
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 5:
				while(z5==0){
					printf("\t\tRegistro de Pedido/Venta\n\n");
					op=submenupedidoventa();
					switch(op){
						case 1:
							strcpy(order[i4].fechapedido,f);
							fflush(stdin);
							puts(order[i4].fechapedido);
							order[i4].subtotal=0;
							order[i4].idpedido=generaridpedido(i4);
							printf("Que se registrara:\n\t1 Pedido\n\t2 Venta\n");
							while(contvalidador==0){
								printf("Selecciona una opcion: ");
								scanf("%d",&order[i4].npedido);
								if(order[i4].npedido==1||order[i4].npedido==2) contvalidador=1;
								else printf("Opcion invalida\n");
							}
							contvalidador=0;
							printf("Id para este pedido/venta: %lu\n\n",order[i4].idpedido);
							printf("Por favor ingresa los datos sobre el pedido/venta que se soliciten:\n\n");
							if(order[i4].npedido==1){
								while(contvalidador==0){
									printf("Ingresa el id del cliente: ");
									scanf("%lu",&order[i4].idcliente);
									i=idexistcliente(order[i4].idcliente);
									if(i==1) contvalidador=1;
									else printf("Este id no existe\n");
								}
								contvalidador=0;
							}
							else order[i4].idcliente=999;
							printf("Ingresa los siguientes datos sobre la fecha entrega (ejemplo: 09/05/18):\n");
							printf("\tDia: ");
							scanf("%d",&order[i4].d);
							printf("\tMes: ");
							scanf("%d",&order[i4].m);
							printf("\tA%co: ",164);
							scanf("%d",&order[i4].a);
							fecha=fopen("Fecha.txt","w");
							if(order[i4].d<10&&order[i4].m<10) fprintf(fecha,"0%d/0%d/%d",order[i4].d,order[i4].m,order[i4].a);
							else{
								if(order[i4].d<10) fprintf(fecha,"0%d/%d/%d",order[i4].d,order[i4].m,order[i4].a);
								else{
									if(order[i4].m<10) fprintf(fecha,"%d/0%d/%d",order[i4].d,order[i4].m,order[i4].a);
									else fprintf(fecha,"%d/%d/%d",order[i4].d,order[i4].m,order[i4].a);
								}
							}
							fclose(fecha);
							if((fecha=fopen("Fecha.txt","r"))==NULL) printf("No se pudo abrir\n\n");
							else{
								while(!feof(fecha)){
									fscanf(fecha,"%s",order[i4].fechaentrega);
								}
							}
							fclose(fecha);
							/*Se iniciara el registro de PEDIDODETALLE*/
							do{
								orderdetail[i5].idpedido=order[i4].idpedido;
								orderdetail[i5].idpedidodet=generaridpedidodetalle(i5);
								printf("Id para este Pedido detalle: %lu\n",orderdetail[i5].idpedidodet);
								printf("id del pedido: %lu\n",orderdetail[i5].idpedido);
								while(contvalidador==0){
									printf("Ingesa el id del producto que se desean comprar: ");
									scanf("%lu",&orderdetail[i5].idproducto);
									i=idexistproduct(orderdetail[i5].idproducto);
									if(i==1) contvalidador=1;
									else printf("Este id no existe\n\n");
								}
								contvalidador=0;
								while(contvalidador==0){
									printf("Cuantas unidades de este producto se desean comprar?: ");
									scanf("%d",&orderdetail[i5].cantidad);				
									for(i=0;i<100;i++){
										if(orderdetail[i5].idproducto==product[i].id) break;
									}
									if(orderdetail[i5].cantidad<=product[i].numexistencia){
										contvalidador=1;
										product[i].numexistencia=product[i].numexistencia-orderdetail[i5].cantidad;
									}
									else printf("No hay suficientes unidades\n");
									
								}
								contvalidador=0;
								orderdetail[i5].precio=orderdetail[i5].cantidad*product[i].precio;
								printf("Precio de esta orden: %.2lf\n\n",orderdetail[i5].precio);
								pedidodet=fopen("Pedido Detalle.txt","a");
								fprintf(pedidodet,"%lu\t%lu\t%lu\t%lu\t%.2lf\n",orderdetail[i5].idpedidodet,orderdetail[i5].idpedido,orderdetail[i5].idproducto,orderdetail[i5].cantidad,orderdetail[i5].precio);
								fclose(pedidodet);
								order[i4].subtotal=order[i4].subtotal+orderdetail[i5].precio;
								printf("Ingrese 0 si desea realizar otro pedido/venta, si no desea realizar otro pedido ingrese cualquier otro numero: ");
								scanf("%d",&i);
								i5++;
							}while(i==0);
							/*Se finaliza el registro de PEDIDODETALLE*/
							printf("Subtotal: %.2lf\n",order[i4].subtotal);
							order[i4].iva=order[i4].subtotal*IVA;
							printf("IVA: %.2lf\n",order[i4].iva);
							order[i4].total=order[i4].subtotal+order[i4].iva;
							printf("TOTAL: %.2lf\n",order[i4].total);
							pedido=fopen("Pedido.txt","a");
							fprintf(pedido,"%lu\t",order[i4].idpedido);
							if(order[i4].npedido==1) fprintf(pedido,"Pedido\t");
							else fprintf(pedido,"Venta\t");
							fprintf(pedido,"%lu\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t",order[i4].idcliente,order[i4].fechapedido,order[i4].fechaentrega,order[i4].subtotal,order[i4].iva,order[i4].total);
							fprintf(pedido,"Activo\t");
							fprintf(pedido,"%d\t%d\t%d\n",order[i4].d,order[i4].m,order[i4].a);
							fclose(pedido);
							if(order[i4].total<=200&&order[i4].npedido==1){
								printf("El pedido debe ser mayor a 200\n\n");
								contvalidador=1;
							}
							if(contvalidador==1){
								order[i4].eatatus=0;
								printf("Pedido cancelado por tener un valor menor a 200\n\n");
							}
							contvalidador==0;
							i4++;
							break;
						case 2:
							if(i4>0){
								printf("Ingresa el Id del pedido: ");
								scanf("%lu",&codigo);	
								for(i=0;i<100;i++){
									if(codigo==order[i].idpedido) break;
								}	
								if(order[i].npedido==1){
									if(order[i].eatatus==0) printf("Este pedido ya se cancelo o no existe\n");
									else order[i].eatatus=0;
								}	
							else printf("No se puede cancelar una venta\n\n");
							}
							else printf("No has hecho ningun pedido\n\n");
						 break;
						case 3:
							contvalidador=0;
							printf("Ingresa el id del cliente: ");
							scanf("%lu",&codigo);
							for(i=0;i<100;i++){
								if(codigo==order[i].idcliente){
									printf("Id Pedido: %lu\n",order[i].idpedido);
									if(order[i].npedido==1) printf("Pedido\n");
									else printf("Venta\n");
									printf("Id Cliente: %lu\nFecha Pedido: %s\nFecha Entrega: %s\nSubtotal: %.2lf\nIVA: %.2lf\nTotal: %.2lf\nEstatus: ",order[i].idcliente,order[i].fechapedido,order[i].fechaentrega,order[i].subtotal,order[i].iva,order[i].total);
									if(order[i].eatatus==0) printf("Inactivo\n\n");
									else{
										if(order[i].eatatus==1) printf("Activo\n\n");
										else printf("Entregado\n\n");
									}
								}
							}
							break;
						case 4:
							for(i=0;i<100;i++){
								if(strcmp(output,order[i].fechaentrega)==0&&order[i].npedido==1&&order[i].eatatus==1){
									printf("Id Pedido: %lu\nId Cliente: %lu\nFecha de pedido: %s\nSubtotal: %lf\nIVA: %lf\nTotal: %lf\n\n",order[i].idpedido,order[i].idcliente,order[i].fechapedido,order[i].subtotal,order[i].iva,order[i].total);
								}
							}
							printf("Ingrese un 0 si desea enviar los pedidos: ");
							scanf("%d",&contvalidador);
							for(i=0;i<100;i++){
								if(strcmp(output,order[i].fechaentrega)==0&&order[i].npedido==1&&contvalidador==0){
									order[i].eatatus=2;
								}
							}
							break;
						case 5:
							z5=1;
							break;
						default:
							printf("Esta opcion no existe\n\n");
					}
					system("pause");
					system("cls");	
				}
				z5=0;
				actualizarpedido(i4);
				break;
			case 6:
				if(power==1){
				printf("Deseas el historial de:\n\t1 Pedidos\n\t2 Ventas\nSelecciona una opcion: ");
				scanf("%d",&op);
				printf("Ingresa los datos de la fecha a partir de la que se empezara a buscar:\n");
				printf("\tDia: ");
				scanf("%d",&d1);
				printf("\tMes: ");
				scanf("%d",&m1);
				printf("\tA%co: ",164);
				scanf("%d",&a1);
				printf("Ingresa los datos de la fecha hasta la cual de buscara:\n");
				printf("\tDia: ");
				scanf("%d",&d2);
				printf("\tMes: ");
				scanf("%d",&m2);
				printf("\tA%co: ",164);
				scanf("%d",&a2);
				system("pause");
				system("cls");
				switch(op){
					case 1:
						contvalidador=0;
						while(contvalidador==0){
							printf("Ingresa la clave del cliente: ");
							scanf("%lu",&codigo);
							i=idexistcliente(codigo);
							if(i==1) contvalidador=1;
							else printf("Este id no existe\n\n");
						}
						system("pause");
						system("cls");
						for(i=0;i<100;i++){
							if(codigo==client[i].id) break;
						}
						printf("\t\tHistorial Pedidos\nClave cliente: %lu\t\t\tNombre Cliente: %s\nDireccion: %s %s, %s\n",client[i].id,client[i].name,client[i].numcasa,client[i].calle,client[i].colonia);
						for(i=0;i<100;i++){
							if(order[i].npedido==1){									//los diferentes if's son utilizados para verificar comprobar que la fechas son validas y asi saber que imprimir
								if(a1<=order[i].a&&a2>=order[i].a){
									if(m1<=order[i].m&&m2>=order[i].m){
										if(d1<=order[i].d&&d2>=order[i].d){
											printf("Fecha de entrega: %s\t\t\t\tEntregado: ",order[i].fechaentrega);
											if(order[i].eatatus==2) printf("Si\n");
											else printf("No\n");
											printf("Clave Producto\t\tDescripcion\t\tCantidad\t\tPrecio\t\tTotal\n");
											for(j=0;j<=i5;j++){
												if(orderdetail[j].idpedido==order[i].idpedido){
													printf("%lu\t\t\t",orderdetail[j].idproducto);
													for(k=0;k<100;k++){
														if(orderdetail[j].idproducto==product[k].id) break;
													}
													total=product[k].precio*orderdetail[j].cantidad;
													printf("%s\t\t\t%lu\t\t\t%.2f\t\t%.2lf\n",product[k].name,orderdetail[j].cantidad,product[k].precio,total);
												}
											}
											printf("%70s: %.2lf\n","Subtotal",order[i].subtotal);
											printf("%70s: %.2lf\n","IVA",order[i].iva);
											printf("%70s: %.2lf\n","Total",order[i].total);
											printf("\n");
										}
									}
								}
							}
						}
						printf("\n\n\n\n");
						break;
					case 2:
						printf("\t\tHistorial Ventas\n");
						for(i=a1;i<=a2;i++){
							for(j=m1;j<=m2;j++){						//estos ciclos son utilizados para buscar los diferentes datos  como fechas y los lugares en los que se gusrdaron los datos
								for(k=d1;k<=d2;k++){
									for(x=0;x<i4;x++){
										if(order[x].d==k&&order[x].m==j&&order[x].a==i&&order[x].npedido==0){
											printf("Fecha: %s\nClave Venta: %lu\n",order[x].fechaentrega,order[x].idpedido);
											printf("Clave Producto\t\tDescripcion\t\tCantidad\t\tPrecio\t\tTotal\n");
											for(y=0;y<=i5;y++){
												if(orderdetail[y].idpedido==order[x].idpedido){
													printf("%lu\t\t\t",orderdetail[y].idproducto);
													for(w=0;w<100;w++){
														if(orderdetail[y].idproducto==product[w].id) break;
													}
													total=product[w].precio*orderdetail[y].cantidad;
													printf("%s\t\t\t%lu\t\t\t%.2f\t\t%.2lf\n",product[w].name,orderdetail[y].cantidad,product[w].precio,total);
												}
											}
											printf("%70s: %.2lf\n","Subtotal",order[x].subtotal);
											printf("%70s: %.2lf\n","IVA",order[x].iva);
											printf("%70s: %.2lf\n","Total",order[x].total);
											printf("\n");
										}
									}
								}
							}
						}
						printf("\n\n\n\n");
						break;
					default:
						printf("Opcion invalida\n\n");
				}
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 7:
				if(power==1){
				contvalidador=0;
				while(contvalidador==0){
					printf("Ingresa el Id del tipo de producto del cual deseas ver el reporte: ");
					scanf("%lu",&codigo);
					i=idexisttipeproduct(codigo);
					if(i==1) contvalidador=1;
					else printf("Este tipo de producto no existe\n");
				}	
				system("pause");
				system("cls");
				printf("Reporte de inventario al dia ");
				fechaimpresion2();
				printf("Tipo producto\tClave producto\tDescripcion\t\tExistencia\n\n");
				for(i=0;i<100;i++){				//imprime los datos que son validos y se necesitan en este reporte
					if(codigo==product[i].idtipo){
						printf("%lu\t\t%lu\t\t%s\t\t\t%lu\n",product[i].idtipo,product[i].id,product[i].name,product[i].numexistencia);
					}
				}
				system("pause");
				system("cls");
				}else printf("\n No tiene permisos aqui\n");
				break;
			case 8:
				z=1;
				break;
	
			default: 
				printf("Opcion no valida!!!\n\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}

int recuperarusuario(){
	
	FILE *ptrcf;
	
	char estatus1[10];
	int i=0,z=0;
	if((ptrcf=fopen("Usuario.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %s %s %s %d %s",&user[z].id,user[z].usuario,user[z].password,user[z].name,&user[z].tipo,estatus1);
			if(strcmp(estatus1,"Activo")==0) user[z].estatus=1;
			else user[z].estatus=0;
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int recuperarclientes(){
	
	FILE *ptrcf;
	
	char estatus1[10];
	int i=0,z=0;
	if((ptrcf=fopen("Cliente.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %s %s %s %s %s %s",&client[z].id,client[z].name,client[z].calle,client[z].colonia,client[z].numcasa,client[z].telefono,estatus1);
			if(strcmp(estatus1,"Activo")==0) client[z].estatus=1;
			else client[z].estatus=0;
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int recuperarproductos(){
	
	FILE *ptrcf;
	
	char estatus1[10];
	int i=0,z=0;
	if((ptrcf=fopen("Producto.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %s %lu %d %f %s",&product[z].id,product[z].name,&product[z].idtipo,&product[z].numexistencia,&product[z].precio,estatus1);
			if(strcmp(estatus1,"Activo")==0) product[z].estatus=1;
			else product[z].estatus=0;
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int recuperartipoproductos(){
	
	FILE *ptrcf;
	
	char estatus1[10];
	int i=0,z=0;
	if((ptrcf=fopen("Tipo_Producto.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %s %s",&tipeproduct[z].id,tipeproduct[z].name,estatus1);
			if(strcmp(estatus1,"Activo")==0) tipeproduct[z].estatus=1;
			else tipeproduct[z].estatus=0;
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int recuperarpedido(){
	
	FILE *ptrcf;
	
	char estatus1[10],npedido1[10];
	int i=0,z=0;
	if((ptrcf=fopen("Pedido.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %s %lu %s %s %lf %lf %lf %s",&order[z].idpedido,npedido1,&order[z].idcliente,order[z].fechapedido,order[z].fechaentrega,&order[z].subtotal,&order[z].iva,&order[z].total,estatus1);
			fscanf(ptrcf,"%d %d %d",&order[z].d,&order[z].m,&order[z].a);
			if(strcmp(npedido1,"Pedido")==0) order[z].npedido=1;
			else order[z].npedido=0;
			if(strcmp(estatus1,"Activo")==0) order[z].eatatus=1;
			else{
				if(strcmp(estatus1,"Entregado")==0) order[z].eatatus=2;
				else order[z].eatatus=0;
			}
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int recuperarpedidodetalle(){
	
	FILE *ptrcf;
	
	int i=0,z=0;
	if((ptrcf=fopen("Pedido Detalle.txt","r"))==NULL) return 0;
	else{
		while(!feof(ptrcf)){
			fscanf(ptrcf,"%lu %lu %lu %lu %lf",&orderdetail[z].idpedidodet,&orderdetail[z].idpedido,&orderdetail[z].idproducto,&orderdetail[z].cantidad,&orderdetail[z].precio);
			z++;
		}
	}
	z--;
	fclose(ptrcf);
	return z;
}

int submenuproductos(){											//Funcion para imprimir el menu del registro de productos
	int op;
	printf("\n\n1 Alta\n2 Baja\n3 Consulta\n4 Resurtido\n5 Regresar men%c principal\n\n  ",163);
	op = validarnumero();
	system("cls");
	return op;
}

int submenu(){													//Funcion para imprimir el menu del registro de usuarios, clientes y tipo de producto
	int op;
	printf("\n\n1 Alta\n2 Baja\n3 Consulta\n4 Regresar men%c principal\n\n ",163);
	op = validarnumero();
	system("cls");
	return op;
}

int submenupedidoventa(){
	int op;
	printf("\n\n1 Alta\n2 Cancelar Pedido\n3 Consulta\n4 Env%co\n5 Regresar men%c principal\n\n ",161,163);
	op = validarnumero();
	system("cls");
	return op;
}

int vnameusuario(char name[50]){
	int s=0,s2=0,i;
	for(i=0;i<strlen(name);i++){								//se evalua de caracter en caracter
		if(name[i]>=65&&name[i]<=90||name[i]>=97&&name[i]<=122||name[i]==45||name[i]==95){//si es un caracter valido se realiza la suma
			s=s+1;
		}
	}
	for(i=0;i<100;i++){
		if(strcmp(name,client[i].name)==0) s2++;
	}
	if(s2>1){
		printf("Este nombre ya existe\n");
		return 0;
	}
	if(strlen(name)==s) return 1;								//si la suma es igual a la longitud de la cadena significa que los caracteres son validos 
	printf("ERROR, el nombre del usuario no cumple los requisitos (Solo ingrese letras o '-' o '_' en lugar de espacios)!!!\n");										//en caso contrario se manda el mensaje de error
	return 0;
}

int vnamecliente(char name[50]){
	int s=0,s2=0,i;
	for(i=0;i<strlen(name);i++){								//se evalua de caracter en caracter
		if(name[i]>=65&&name[i]<=90||name[i]>=97&&name[i]<=122||name[i]==45||name[i]==95){//si es un caracter valido se realiza la suma
			s=s+1;
		}
	}
	for(i=0;i<100;i++){
		if(strcmp(name,client[i].name)==0) s2++;
	}
	if(s2>1){
		printf("Este nombre ya existe\n");
		return 0;
	}
	if(strlen(name)==s) return 1;				//si la suma es igual a la longitud de la cadena significa que los caracteres son validos 
	printf("ERROR!!!\n");						//en caso contrario se manda el mensaje de error
	return 0;
}

int vpassword(char password[8]){
	int s=0,M=0,n=0,i;
	for(i=0;i<strlen(password);i++){								//se evalua de caracter en caracter
		if(password[i]>=65&&password[i]<=90||password[i]>=97&&password[i]<=122||password[i]==45 || password[i]==46 || password[i]>=48&&password[i]<=57){//si es un caracter valido se realiza la suma
			s=s+1;
		}
	}
	
	for(i=0;i<=strlen(password);i++){ 			// Este FOR permite identificar la cantidad de letras Maysuculas dentro de nuestra contraseña
		if(password[i]>=65&&password[i]<=90){
			M=M+1;
		} 
	}
	
	for(i=0;i<=strlen(password);i++){          //Este FOR permite identificar la cantidad de numeros que se encuentran en la contraseña
		if(password[i]>=48&&password[i]<=57){
			n=n+1;
		} 
	}
			
	if(strlen(password)==s && strlen(password)==8 && M>=1 && n>=1) return 1;	//Verifica que todos los requisitos de la contraseña se cumplan (Longitud de la contraseña, al menos una mayuscula o un numero)
	printf("ERROR, el password no cumple con los requisitos necesarios (\n1.8 caracteres\n2.Al menos una mayuscula\n3.Al menos un numero\n4.Solo los signos (punto y guion medio) !!!\n\n");	//en caso contrario se manda el mensaje de error
	return 0;
}

int vusuario(char usuario[6]){
	int s=0,s2=0,i;
	for(i=0;i<strlen(usuario);i++){								//se evalua de caracter en caracter					
			s=s+1;
	}
	for(i=0;i<100;i++){
		if(strcmp(usuario,user[i].usuario)==0) s2++;
	}
	if(s2>1){
		printf("Este usuario ya existe\n");
		return 0;
	}
	if(strlen(usuario)==s && strlen(usuario)<=6) return 1;								//si la suma es igual a la longitud de la cadena y ademas no supera los 6 digitos que significa que los caracteres son validos  
	printf("ERROR, el usuario no cumple los requisitos para dar de alta (Maximo 6 caracteres)!!!\n");										//en caso contrario se manda el mensaje de error
	return 0;
}

int vtipo(int tipo){
	if(tipo==1 || tipo==2){
		printf("Se ha asignado el tipo de usuario\n\n");
		return 1;	
	} else {
		printf("Error, el tipo de usuario no existe (Seleccione 1.-Administrador o 2.- Cajero)!\n\n"); 
		return 0;
	}

}	

int vnameproducto(char name[50]){
	int s=0,i;
	for(i=0;i<strlen(name);i++){								//se evalua de caracter en caracter
		if(name[i]==32){//si es un caracter no valido se realiza la suma
			s=s+1;
		}
	}
	for(i=0;i<100;i++){
		if(strcmp(name,product[i].name)==0) s++;
	}
	if(s>1){
		printf("Este nombre ya existe o no cumple los requisitos\n");
		return 1;
	}
	return 0;
}

int vnametipoproducto(char name[50]){
	int s=0,s2=0,i;
	for(i=0;i<strlen(name);i++){								//se evalua de caracter en caracter
		if(name[i]==32){//si es un caracter no valido se realiza la suma
			s2++;
		}
	}
	for(i=0;i<100;i++){
		if(strcmp(name,tipeproduct[i].name)==0) s2++;
	}
	if(s2>1){
		printf("Este nombre ya existe o no cumple los requisitos\n");
		return 1;
	}
	return 0;
}

int vtel(char tel[50]){
	int s=0,i;
	for(i=0;i<strlen(tel);i++){									//se evalua de caracter en caracter
		if(tel[i]>=48&&tel[i]<=57){								//si es un caracter valido se realiza la suma
			s=s+1;
		}
	}
	if(strlen(tel)==s) return 1;								//si la suma es igual a la longitud de la cadena significa que los caracteres son validos 
	printf("ERROR!!!\n");										//en caso contrario se manda el mensaje de error
	s=0;
	return 0;
}

long generaridusuario(int i){
	int z;
	z=1001+i;
	return z;
}

long generaridcliente(int i){
	int z;
	z=2001+i;
	return z;
}

long generaridproducto(int i){
	int z;
	z=3001+i;
	return z;
}

long generaridtipoproducto(int i){
	int z;
	z=4001+i;
	return z;
}

long generaridpedido(int i){
	int z;
	z=5001+i;
	return z;
}

long generaridpedidodetalle(int i){
	int z;
	z=6001+i;
	return z;
}

int nameexistuser(char name[50]){
	int s=0,i;
	for(i=0;i<100;i++){
		if(strcmp(name,user[i].name)==0) s++;
	}
	if(s==0) return 0;
	else return 1;
}

int nameexistcliente(char name[50]){
	int s=0,i;
	for(i=0;i<100;i++){
		if(strcmp(name,client[i].name)==0) s++;
	}
	if(s==0) return 0;
	else return 1;
}

int nameexistproducto(char name[50]){
	int s=0,i;
	for(i=0;i<100;i++){
		if(strcmp(name,product[i].name)==0) s++;
	}
	if(s==0) return 0;
	else return 1;
}

int nameexisttipoproducto(char name[50]){
	int s=0,i;
	for(i=0;i<100;i++){
		if(strcmp(name,tipeproduct[i].name)==0) s++;
	}
	if(s==0){
		printf("Este tipo de producto no existe\n\n");
		return 0;	
	}
	else return 1;
}

int idexistcliente(long id){
	int s=0,i;
	for(i=0;i<100;i++){
		if(client[i].id==id) s++;
	}
	if(s==0) return 0;
	else return 1;
}

int idexistproduct(long id){
	int s=0,i;
	for(i=0;i<100;i++){
		if(product[i].id==id) s++;
	}
	if(s==0) return 0;
	else return 1;
}

void fechaimpresion(){
	 time_t tiempo = time(0); 
        struct tm *tlocal = localtime(&tiempo);                      
        char output[128];
        strftime(output,128,"Impresion del reporte: %d/%m/%y",tlocal);  //Imprime la fecha actual en que se genera el inventario
        printf("%s\n",output);
}

int validarnumero(){
   char cadena[100000];
   int numero;
   printf("\n\nSelecciona una opci%cn: ",162);
   scanf("%s",cadena);
      numero=atoi(cadena);         //Hace que una cadena cualquiera se vuelva entero 
      return numero;
}

void fechaimpresion2(){
	 time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y",tlocal);
        printf("%s\n",output);
}

int idexisttipeproduct(long id){
	int s=0,i;
	for(i=0;i<100;i++){
		if(tipeproduct[i].id==id) s++;
	}
	if(s==0) return 0;
	else return 1;
}

int login(){
		int i=0,v=0;
		char usuario[10];
		char contrasena[10];
	struct ac reg[50];
	fflush(stdin);
		
	FILE * REG;
	REG = fopen("Registro.bin","rb");
	if (REG == NULL){printf("ERROR 404");
	return 16;
}
printf("\t\tBienvenidos\t\t\n\n");
printf("\t    Supermercado FCFM\t\n");
printf("Usuario: ");
gets(usuario);
strcpy(reus,usuario);
fflush(stdin);
printf("Password: ");
while(contrasena[i]!=13){
contrasena[i]=getch();
    if(contrasena[i]>32 && i<10){
printf("*");
i++;
}else
if(contrasena[i]==8&&i>0){
                 putchar(8);
                 printf(" ");
                 putchar(8);
                 i--;
}
}
contrasena[i]='\0';
getch();
while(!feof(REG)){
fflush(stdin);
fread(&reg[i],sizeof(struct ac),1,REG);
if(strcmp(usuario,reg[i].user)==0){
if(strcmp(contrasena,reg[i].pass)==0)
 v++;}
if (v==1) break;
i++;
}
system("cls");
if(v==1) { 
printf("\n\tCLAVE VALIDA\n");
system("pause");
system("cls");
return usuario;
}
else printf("\n\tCLAVE ERRONEA\n");

system("pause");
system("cls");
return 0;
}

void actualizarusuarios(int i6){
	
	FILE *usuario;
	
	int i;
	usuario=fopen("Usuario.txt","w");
	for(i=0;i<i6;i++){
		fprintf(usuario,"%lu\t%s\t%s %s\t%d ",user[i].id,user[i].usuario,user[i].password,user[i].name,user[i].tipo);
		if(user[i].estatus==1) fprintf(usuario,"Activo\n");
		else fprintf(usuario,"Inactivo\n");
	}
	fclose(usuario);
}

void actualizarclientes(int i1){
	
	FILE *cliente;
	
	int i;
	cliente=fopen("Cliente.txt","w");
	for(i=0;i<i1;i++){
		fprintf(cliente,"%lu\t%s\t%s\t%s\t%s\t%s\t",client[i].id,client[i].name,client[i].calle,client[i].colonia,client[i].numcasa,client[i].telefono);
		if(client[i].estatus==1) fprintf(cliente,"Activo\n");
		else fprintf(cliente,"Inactivo\n");
	}
	fclose(cliente);
}

void actualizarproductos(int i2){
	
	FILE *producto;
	
	int i;
	producto=fopen("Producto.txt","w");
	for(i=0;i<i2;i++){
		fprintf(producto,"%lu\t%s\t%lu\t%d\t%.2f\t",product[i].id,product[i].name,product[i].idtipo,product[i].numexistencia,product[i].precio);
		if(product[i].estatus==1) fprintf(producto,"Activo\n");
		else fprintf(producto,"Inactivo\n");
	}
	fclose(producto);
}

void actualizartipoproducto(int i3){
	
	FILE *tipo;
	
	int i;
	tipo=fopen("Tipo_Producto.txt","w");
	for(i=0;i<i3;i++){
		fprintf(tipo,"%lu\t%s\t",tipeproduct[i].id,tipeproduct[i].name);
		if(tipeproduct[i].estatus==1) fprintf(tipo,"Activo\n");
		else fprintf(tipo,"Inactivo\n");
	}
	fclose(tipo);
}

void actualizarpedido(int i4){
	
	FILE *pedido;
	
	int i;
	pedido=fopen("Pedido.txt","w");
	for(i=0;i<i4;i++){
		fprintf(pedido,"%lu\t",order[i].idpedido);
		if(order[i].npedido==1) fprintf(pedido,"Pedido\t");
		else fprintf(pedido,"Venta\t");
		fprintf(pedido,"%lu\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t",order[i].idcliente,order[i].fechapedido,order[i].fechaentrega,order[i].subtotal,order[i].iva,order[i].total);
		if(order[i].eatatus==1) fprintf(pedido,"Activo\t");
		else{
			if(order[i].eatatus==2) fprintf(pedido,"Entregado\t");
			else fprintf(pedido,"Inactivo\t");
		}
		fprintf(pedido,"%d\t%d\t%d\n",order[i].d,order[i].m,order[i].a);
	}
	fclose(pedido);
}

int espacios(char name[50]){
	int i,s=0;
	for(i=0;i<strlen(name);i++){
		if(name[i]==32) s++;
	}
	if(s==0) return 0;
	else return 1;
}
