#include <QAbstractListModel>
#include <QStringList>

class AudioFileInfo
{
public:
    AudioFileInfo(const QString &tduringTime, const QString &tcreatedTime, int trank);

    QString getDuringTime() const;
    QString getCreatedTime() const;
    QString getRank() const;

private:
    QString duringTime;
    QString createdTime;
    QString rank;
};

class AudioFileInfoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AudioFileInfoRoles {
        DuringTimeRole = Qt::UserRole + 1,
        CreatedTimeRole,
        RankRole
    };

    AudioFileInfoModel(QObject *parent = 0);

    void addAudioFileInfo(const AudioFileInfo &aFileInfo);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<AudioFileInfo> fileInfoList;
};


