#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  void startsOff();
  void clickTurnsOn();
  void clickTwoTurnsOff();
  void alternateClicks();
};

// Implement the tests here
static QPushButton *findSwitch(ToggleWidget &w) {
  return w.findChild<QPushButton *>();
}

void TestToggleWidget::startsOff() {
  ToggleWidget w;
  QVERIFY(!w.isOn());
}

void TestToggleWidget::clickTurnsOn() {
  ToggleWidget w;
  QPushButton *pushBtn = findSwitch(w);
  QVERIFY(pushBtn != nullptr);

  QTest::mouseClick(pushBtn, Qt::LeftButton);
  QVERIFY(w.isOn());
}

void TestToggleWidget::clickTwoTurnsOff() {
  ToggleWidget w;
  QPushButton *pushBtn = findSwitch(w);
  QVERIFY(pushBtn != nullptr);

  QTest::mouseClick(pushBtn, Qt::LeftButton);
  QVERIFY(w.isOn());
  QTest::mouseClick(pushBtn, Qt::LeftButton);
  QVERIFY(!w.isOn());
}

void TestToggleWidget::alternateClicks() {
  ToggleWidget w;
  QPushButton *pushBtn = findSwitch(w);
  QVERIFY(pushBtn != nullptr);

  for (int c = 1; c <= 8; c++) {
    QTest::mouseClick(pushBtn, Qt::LeftButton);
    QCOMPARE(w.isOn(), c%2 == 1); // every even click should turn it off
  }
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
