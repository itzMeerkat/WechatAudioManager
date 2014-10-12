#include <QAbstractListModel>
#include <QStringList>

//![0]
class AudioFileInfo
{
public:
    AudioFileInfo(const QString &tduringTime, const QString &tcreatedTime);
//![0]

    QString getDuringTime() const;
    QString getCreatedTime() const;

private:
    QString duringTime;
    QString createdTime;
//![1]
};

class AudioFileInfoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AudioFileInfoRoles {
        DuringTimeRole = Qt::UserRole + 1,
        CreatedTimeRole
    };

    AudioFileInfoModel(QObject *parent = 0);
//![1]

    void addAudioFileInfo(const AudioFileInfo &aFileInfo);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<AudioFileInfo> fileInfoList;
//![2]
};
//![2]


