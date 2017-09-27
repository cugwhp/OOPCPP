程序功能：基于MFC的GDI显示遥感图像。
细节：1.图像IO采用GDAL；
	  2.简单的波段组合，生成RGB Bitmap；
	  3.GDI显示Bitmap；
	  
关键点：
1. OnFileOpen
	重载了文件打开消息
2. OpenDocumentFile
	重载文档打开，GDALOpen打开Dataset
3. OnDraw
	显示图像，包括RasterIO、Bitmap生成、显示