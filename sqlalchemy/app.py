import select
from typing import List, Optional
from click import Option
from matplotlib import category
from more_itertools import quantify
from sqlalchemy import ForeignKey, String
from sqlalchemy.orm import DeclarativeBase, Mapped, mapped_column, relationship, Session

class Base(DeclarativeBase):
    pass

class Customer(Base):
    __tablename__ = "customer"
    id: Mapped[int] = mapped_column(primary_key=True)
    name: Mapped[str] = mapped_column(String(30))
    fullname: Mapped[Optional[str]]
    email_address: Mapped[str]
    address : Mapped[str]
    country_code : Mapped[str] = mapped_column(String(2))
    credit_card: Mapped["CreditCard"] = relationship("CreditCard", uselist = False, back_populates="customer")
    orders: Mapped[List["Order"]] = relationship("Order", back_populates="customer")
    def __repr__(self) -> str:
        return f"<Customer(name={self.name}, fullname={self.fullname}, email_address={self.email_address}, address={self.address}, country_code={self.country_code})>"
    
class CreditCard(Base):
    __tablename__ = "credit_card"
    id: Mapped[int] = mapped_column(primary_key=True)
    customer_id: Mapped[int] = mapped_column(ForeignKey("customer.id"))
    customer: Mapped[Customer] = relationship("Customer", back_populates="credit_card")
    number : Mapped[str] = mapped_column(String(19))

    def __repr__(self) -> str:
        return f"<CreditCard(number={self.number})>"

# add a Product with name, price, description and category.
class Product(Base):
    __tablename__ = "product"
    id: Mapped[int] = mapped_column(primary_key=True)
    name: Mapped[str] = mapped_column(String(100))
    price: Mapped[float]
    description: Mapped[str]
    category: Mapped[str] = mapped_column(String(100))
    orders: Mapped[List["Order"]] = relationship("Order", back_populates="product")
    def __repr__(self) -> str:
        return f"<Product(name={self.name}, price={self.price}, description={self.description}, category={self.category})>"
    
class Order(Base):
    __tablename__ = "order"
    id: Mapped[int] = mapped_column(primary_key=True)
    customer_id: Mapped[int] = mapped_column(ForeignKey("customer.id"))
    customer: Mapped[Customer] = relationship("Customer", back_populates="orders")
    product_id: Mapped[int] = mapped_column(ForeignKey("product.id"))
    product: Mapped[Product] = relationship("Product", back_populates="orders")
    quantify: Mapped[int]

    def __repr__(self) -> str:
        return f"<Order(customer_id={self.customer_id}, product_id={self.product_id}, quantify={self.quantify})>"
    
from sqlalchemy import create_engine
from faker import Faker
fake = Faker(["en_US", "en_GB", "en_CA", "es_MX"])

engine = create_engine("sqlite:///my_database.db", echo = True)
Base.metadata.create_all(engine)

with Session(engine) as session:
    for i in range(10):
        product = Product(name = f"Product {i}", price = 9.99*i, description = "ABC", category = "XYZ")
        session.add(product)
    for i in range(100):
        customer = Customer(
            name = fake.name(), 
            email_address = fake.email(), 
            address = fake.address(), 
            country_code = fake.country_code())
        session.add(customer)

        credit_card = CreditCard(number = fake.credit_card_number(), customer = customer)
        session.add(credit_card)
        for _ in range(fake.random_int(min = 1, max = 5)):
            order = Order(customer = customer, product_id = fake.random_int(min = 1, max = 10),
                      quantify = fake.random_int(min = 1, max = 5))
            session.add(order)
    session.commit()

    from sqlalchemy import select
    query = select(Customer)
    results = session.execute(query).scalars().all()
    print(results)

    query  = select(Customer).where(Customer.country_code == "US")
    results = session.execute(query).scalars().all()
    print(results)

    from sqlalchemy import func
    query = select(Customer.country_code, func.count(Customer.country_code)).group_by(Customer.country_code)

    results = session.execute(query).all()
    print(results)

    # select customer name with credit card number
    query = select(Customer.name, CreditCard.number).join(CreditCard)
    results = session.execute(query).all()
    print(results)

    # select customer name with their number of orders.
    query = select(Customer.id, func.Count(Order.id)).join(Order).group_by(Customer.id)
    results = session.execute(query).all()
    print(results)

    