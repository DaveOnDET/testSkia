// HelloSkia.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "SkPoint.h"
#include "SkImageEncoder.h"
#include "SkScalar.h"
#include "SkColor.h"
#include "SkCanvas.h"
#include "SkBitmap.h"

bool drawSome(SkCanvas* canvas){
	SkPaint paint;
	paint.setStrokeWidth(0.5f);
	paint.setAntiAlias(true);
	paint.setStyle(SkPaint::kStroke_Style);
	canvas->drawLine(0, 0, 100, 100, paint);
	return true;
}
//绘制三角条
void drawTriStrips(SkCanvas* canvas){
	SkPaint filPaint;
	filPaint.setAntiAlias(true);
	filPaint.setStyle(SkPaint::kFill_Style);

	SkPoint testPts[6] = { SkPoint::Make(0, 0), SkPoint::Make(20, 0),
		SkPoint::Make(0, 20), SkPoint::Make(20, 20),
		SkPoint::Make(0, 40), SkPoint::Make(20, 40) };
	SkColor colors[6] = { SK_ColorGREEN, SK_ColorRED, SK_ColorYELLOW, SK_ColorBLUE, SK_ColorGREEN, SK_ColorRED };
	canvas->drawVertices(SkCanvas::kTriangleStrip_VertexMode, 6, &testPts[0], nullptr, &colors[0], nullptr, nullptr, 0, filPaint);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SkPoint pt = SkPoint::Make(0, 0);
	// 重置位图
	int bmpwidth=100, bmpHeight=100;
	SkBitmap bitmapCanvas;
	//bitmap.allocN32Pixels(width, height);
	if (!bitmapCanvas.tryAllocN32Pixels(bmpwidth, bmpHeight)) {
		assert(false);
		return 0;
	}
	SkCanvas canvas(bitmapCanvas);
	canvas.clear(SK_ColorTRANSPARENT);//支持透明色SK_ColorTRANSPARENT
	//绘制
	bool btet =drawSome(&canvas);
	drawTriStrips(&canvas);

	if (btet)
	{
		std::string str = "test.png";
		// TODO: 根据后缀名定义
		SkImageEncoder::EncodeFile(str.c_str(), bitmapCanvas, SkImageEncoder::kPNG_Type, 100);
	}
	return 0;
}


