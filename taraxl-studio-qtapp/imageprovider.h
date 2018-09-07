#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <iostream>

#include <QQuickImageProvider>
#include <QPixmap>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class ImageProvider: public QQuickImageProvider {

public:
    static ImageProvider* getInstance();

    QPixmap requestPixmap(const QString& id,
                          QSize* size,
                          const QSize& requestedSize);

    cv::Mat m_left;

    cv::Mat m_right;

    cv::Mat m_disp0;

    cv::Mat m_disp1;

private:
    static ImageProvider* instance;

    ImageProvider();

    explicit ImageProvider(ImageType type);

    ~ImageProvider();
};

#endif // IMAGEPROVIDER_H
