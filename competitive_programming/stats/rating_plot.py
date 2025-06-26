import numpy as np
from PyQt6.QtCore import QRectF, QTimer
from PyQt6.QtWidgets import QApplication, QMainWindow, QGraphicsRectItem
import pyqtgraph as pg
import sys
import json
from datetime import datetime
from common import ContestResult, DATE_FORMAT

handle = "BritoAlv"
file_path = f"{handle}_standings.json"

class HoverRectItem(QGraphicsRectItem):
    def __init__(self, rect, contest_name, callback):
        super().__init__()
        self.setRect(rect)
        self.contest_name = contest_name
        self.callback = callback
        self.setAcceptHoverEvents(True)
        self.setPen(pg.mkPen(None))  # No border
        self.original_brush = pg.mkBrush(0, 0, 0, 0)
        self.setBrush(self.original_brush)

    def hoverEnterEvent(self, event):
        self.setBrush(pg.mkBrush(0, 0, 0, 0))
        self.callback(self.contest_name, self.rect().center())
        super().hoverEnterEvent(event)

    def hoverLeaveEvent(self, event):
        self.setBrush(self.original_brush)
        self.callback(None, None)
        super().hoverLeaveEvent(event)

class PlotWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle(f"{handle} - Div 2 / Educational Contest Ranks")
        self.resize(1000, 600)

        # Load and filter data
        with open(file_path, "r") as f:
            data = json.load(f)
            existing_results = {k: ContestResult(**v) for k, v in data.items()}

        filtered_contest = [
            cont for cont in existing_results.values()
            if cont.rank > 0 and ("Div. 2" in cont.contest_name or "Educational" in cont.contest_name)
        ]

        sorted_by_date = sorted(
            filtered_contest, key=lambda x: datetime.strptime(x.date_participated, DATE_FORMAT)
        )

        self.contest_names = [res.contest_name for res in sorted_by_date]
        self.ranks = [res.rank for res in sorted_by_date]

        self.plot_data()

    def plot_data(self):
        self.plot_widget = pg.PlotWidget()
        self.setCentralWidget(self.plot_widget)

        x = list(range(len(self.contest_names)))
        y = self.ranks
        self.plot_widget.getPlotItem().hideAxis("bottom")

        # Line plot
        self.plot_widget.plot(x, y, pen=pg.mkPen('b', width=2))
        # Scatter plot
        ranks_arr = np.array(self.ranks)
        min_rank, max_rank = ranks_arr.min(), ranks_arr.max()
        norm_ranks = (ranks_arr - min_rank) / (max_rank - min_rank) if max_rank > min_rank else np.zeros_like(ranks_arr)

        # Define a color map (blue to red)
        cmap = pg.ColorMap([0, 1], [(0, 0, 255), (255, 0, 0)])

        self.spots = []
        for i, (xi, yi) in enumerate(zip(x, y)):
            color = cmap.map(norm_ranks[i], 'qcolor')
            data = self.contest_names[i] + "-" + str(self.ranks[i])
            self.spots.append({
                'pos': (xi , yi),
                'data': data,
                'brush': color,
                'symbol': 'o',
                'size': 20,
            })

        self.scatter = pg.ScatterPlotItem(spots=self.spots)
        self.plot_widget.addItem(self.scatter)

        # Hover text item
        self.text_item = pg.TextItem("", anchor=(0, 1), border='w', fill=(0, 0, 0, 150))
        self.text_item.hide()
        self.plot_widget.addItem(self.text_item)

        # keep the view fixed
        self.plot_widget.setXRange(-5, len(self.contest_names) + 5)
        self.plot_widget.setYRange(min(self.ranks) - 400, max(self.ranks) + 400)

        # Disable auto-range and mouse interaction
        # Enable mouse interaction (zoom/pan)
        vb = self.plot_widget.getPlotItem().vb
        vb.setMouseEnabled(x=True, y=True)

        # Set limits for zoom/pan
        vb.setLimits(
            xMin=-5, xMax=len(self.contest_names) + 5,
            yMin=min(self.ranks) - 400, yMax=max(self.ranks) + 400
        )

        def add_rects():
            vb = self.plot_widget.getPlotItem().vb
            # Desired square size in screen pixels
            pixel_size = 16
            for i, (xi, yi) in enumerate(zip(x, y)):
                # Get data units per pixel at (xi, yi)
                dx, dy = vb.viewPixelSize()
                rect_width = pixel_size * dx
                rect_height = pixel_size * dy
                rect = QRectF(xi - rect_width / 2, yi - rect_height / 2, rect_width, rect_height)
                rect_item = HoverRectItem(rect, self.spots[i]['data'], self.show_contest_name)
                vb.addItem(rect_item)

        # Call after the window is shown to ensure correct scaling
        QTimer.singleShot(0, add_rects)


    def show_contest_name(self, name, pos):
        if name is not None:
            self.text_item.setText(name)
            self.text_item.setPos(pos.x() - len(name)/2, pos.y())
            self.text_item.show()
        else:
            self.text_item.hide()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = PlotWindow()
    window.show()
    sys.exit(app.exec())
